#region Day 6

Hashtable ht = new Hashtable();
private void Day6_1()
{
	List<int> data = Day6_ReadData();

	long total = 0;

	foreach (int i in data)
	{
		long ii = Day6_Produce(i, 256);
		total += ii;
	}

	ctrlResult.Text = total.ToString();
}

private long Day6_Produce(int num, int count)
{
	if (count <= 0) return 1;

	string key = num + "_" + count;
	if (ht.Contains(key)) return (long)ht[key];

	count--;

	long result = 0;
	if (num == 0)
	{
		result += Day6_Produce(8, count) + // new fish
				  Day6_Produce(6, count);  // refresh fish
	}
	else
	{
		result += Day6_Produce(0, count - num + 1);
	}

	ht.Add(key, result);

	return result;
}

private List<int> Day6_ReadData()
{
	StreamReader streamReader = new StreamReader("z:\\Projects\\AdventofCode\\Data\\day6_data.txt");
	string value = streamReader.ReadLine();
	streamReader.Close();

	List<int> result = value.Split(',').Select(a => Convert.ToInt32(a)).ToList();

	return result;
}
#endregion Day 6