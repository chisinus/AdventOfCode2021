#region Day 11
class Day11_Data
{
	public int Number { get; set; }
	public bool Flashed { get; set; }

	public Day11_Data(int n)
	{
		Number = n; 
		Flashed = false;
	}
}

private void Day11_1()
{
	Day11_Data[][] data = Day11_ReadData();

	int total = 0;
	for (int k=1; k<=100; k++)
	{
		List<Tuple<int, int>> flashed = new List<Tuple<int, int>>();
		for (int i = 0; i < data.Length; i++)
		{
			for (int j = 0; j < data[i].Length; j++)
			{
				flashed.AddRange(Day11_Process(data, i, j));
			}
		}

		total += flashed.Count;
		foreach (Tuple<int, int> t in flashed)
		{
			data[t.Item1][t.Item2].Flashed = false;
		}
	}

	ctrlResult.Text = total.ToString();
}

private void Day11_2()
{
	Day11_Data[][] data = Day11_ReadData();

	int count = 0;
	while (true)
	{
		count++;
		List<Tuple <int, int>> flashed = new List<Tuple<int, int>>();
		for (int i = 0; i < data.Length; i++)
		{
			for (int j = 0; j < data[i].Length; j++)
			{
				flashed.AddRange(Day11_Process(data, i, j));
			}
		}

		if (flashed.Count == 100) break;

		foreach (Tuple<int, int> t in flashed)
		{
			data[t.Item1][t.Item2].Flashed = false;
		}
	}

	ctrlResult.Text = count.ToString();
}


private List<Tuple<int, int>> Day11_Process(Day11_Data[][] data, int i, int j)
{
	if ((i < 0) || (j < 0) || (i == data.Length) || (j == data[i].Length) || data[i][j].Flashed)
		return new List<Tuple<int, int>>();        
		
	data[i][j].Number++;
	if (data[i][j].Number < 10) return new List<Tuple<int, int>>();

	data[i][j].Flashed = true; // processed
	data[i][j].Number = 0;

	List<Tuple<int, int>> result = new List<Tuple<int, int>>() { new Tuple<int, int>(i, j) };
	result.AddRange(Day11_Process(data, i, j - 1));         // left
	result.AddRange(Day11_Process(data, i - 1, j));         // top
	result.AddRange(Day11_Process(data, i, j + 1));         // right
	result.AddRange(Day11_Process(data, i + 1, j));         // bottom
	result.AddRange(Day11_Process(data, i - 1, j - 1));     // left top  
	result.AddRange(Day11_Process(data, i - 1, j + 1));     // right top
	result.AddRange(Day11_Process(data, i + 1, j - 1));     // left bottom
	result.AddRange(Day11_Process(data, i + 1, j + 1));     // right bottom

	return result;
}

private Day11_Data[][] Day11_ReadData()
{
	List<Day11_Data[]> result = new List<Day11_Data[]>();
	StreamReader streamReader = new StreamReader("z:\\Projects\\AdventofCode\\Data\\day11_data.txt");
	string value = streamReader.ReadLine();
	while (value != null)
	{
		Day11_Data[] data = new Day11_Data[value.Length];
		for (int i = 0; i < value.Length; i++)
		{
			data[i] = new Day11_Data(Convert.ToInt32(value.Substring(i, 1)));
		}

		result.Add(data);

		value = streamReader.ReadLine();
	}
	streamReader.Close();

	return result.ToArray();
}
#endregion Day 11
