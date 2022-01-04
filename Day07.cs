#region Day 7
class Day7_Data
{
	public int Number { get; set; }
	public int Count { get; set; }
}

List<Day7_Data> Day7Data = new List<Day7_Data>();
private void Day7_1()
{
	Day7Data = Day7_ReadData();

	long min = -1;
	foreach (Day7_Data data in Day7Data)
	{
		long diff = Day7Data.Where(a => a.Number != data.Number).Select(b => Math.Abs((b.Number - data.Number)) * b.Count).Sum();
		if ((diff < min) || min == -1)
			min = diff;
	}

	ctrlResult.Text = min.ToString();
}

private void Day7_2()
{
	Day7Data = Day7_ReadData();

	long min = -1;
	for (int i= Day7Data[0].Number; i<=Day7Data[Day7Data.Count-1].Number; i++)
	{
		long diff = Day7Data.Where(a => a.Number != i).Select(b => Day7_Calculate(Math.Abs(b.Number - i)) * b.Count).Sum();
		if ((diff < min) || min == -1)
			min = diff;
	}

	ctrlResult.Text = min.ToString();
}

private long Day7_Calculate(int num)
{
	int total = 0;
	for (int i=1; i<=num; i++)
	{
		total += i;
	}

	return total;
}

private List<Day7_Data> Day7_ReadData()
{
	StreamReader streamReader = new StreamReader("z:\\Projects\\AdventofCode\\Data\\day7_data.txt");
	string value = streamReader.ReadLine();
	streamReader.Close();

	List<Day7_Data> result = value.Split(',').Select(a => Convert.ToInt32(a)).GroupBy(b=>b).SelectMany(c=>c.Select(d=>new { Number = d, Count = c.Count() })).Distinct().OrderBy(e=>e.Number)
		.Select(a=>new Day7_Data { Number = a.Number, Count = a.Count }).ToList();

	return result;
}
#endregion Day 7
