#region Day 14
Dictionary<string, char> Day14_Rules;
Dictionary<string, long> Pairs;
private void Day14_1()
{
	Day14_ReadData();

	Day14_Process(10);
}

private void Day14_2()
{
	Day14_ReadData();

	Day14_Process(40);
}

private void Day14_Process(int rounds)
{
	for (int i = 0; i < rounds; i++)
	{
		Pairs = Pairs.SelectMany(p => new Dictionary<string, long>()
					{
						{ "" + p.Key[0] + Day14_Rules[p.Key], p.Value },                                // only sum second later.
						{ "" + Day14_Rules[p.Key] + p.Key[1], p.Value }
					}).GroupBy(p => p.Key).ToDictionary(v => v.Key, s => s.Sum(g => g.Value));
	}

	var counts = Day14_Rules.SelectMany(r => r.Key.ToArray())
							.Distinct()
							.Select(c => Pairs.Sum(p => p.Key[1] == c ? p.Value : 0) +                     // Sum second element in each pair
										 (c == Pairs.First().Key[0] ? Pairs.First().Value : 0)             // First element in first pair only exists in first pair
						   );
	
	ctrlResult.Text = (counts.Max() - counts.Min()).ToString();
}

private void Day14_ReadData()
{
	Day14_Rules = new Dictionary<string, char>();

	StreamReader streamReader = new StreamReader("z:\\Projects\\AdventofCode\\Data\\day14_data.txt");
	string template = streamReader.ReadLine();
	Pairs = template.Skip(1).Select((c, i) => "" + template[i] + c)
			.GroupBy(a => a)
			.ToDictionary(b => b.Key, b => long.Parse(b.Count().ToString()));

	streamReader.ReadLine();
	// read rules
	string value = streamReader.ReadLine();
	while (value != null)
	{
		Day14_Rules.Add(value.Substring(0, 2), value[6]);

		value = streamReader.ReadLine();
	}
	streamReader.Close();
}
#endregion Day 14