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
		bool flashed = false;
		for (int i = 0; i < data.Length; i++)
		{
			for (int j = 0; j < data[i].Length; j++)
			{
				int n = Day11_Process(data, i, j);
				if (n > 0) flashed = true;
				total += n;
			}
		}

		if (!flashed) continue;

		for (int i = 0; i < data.Length; i++)
		{
			data[i].Where(a => a.Flashed).ToList().ForEach(a => { a.Flashed = false; a.Number = 0; });
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
		bool flashed = false;
		for (int i = 0; i < data.Length; i++)
		{
			for (int j = 0; j < data[i].Length; j++)
			{
				if (Day11_Process(data, i, j) > 0) flashed = true;
			}
		}

		if (flashed)
		{
			bool all = true;
			for (int i = 0; i < data.Length; i++)
			{
				all = all && !data[i].Any(a => !a.Flashed);
				data[i].Where(a => a.Flashed).ToList().ForEach(a => { a.Flashed = false; a.Number = 0; });
			}

			if (all) break;
		}
	}

	ctrlResult.Text = count.ToString();
}


private int Day11_Process(Day11_Data[][] data, int i, int j)
{
	if ((i < 0) || (j < 0) || (i == data.Length) || (j == data[i].Length))  // invalid position
		return 0;        
		
	data[i][j].Number++;
	if (data[i][j].Number < 10 || data[i][j].Flashed) return 0;

	data[i][j].Flashed = true; // processed
	data[i][j].Number = 0;

	int result = Day11_Process(data, i, j - 1)          //left
				 + Day11_Process(data, i - 1, j)        // top
				 + Day11_Process(data, i, j + 1)        // right
				 + Day11_Process(data, i + 1, j)        // bottom
				 + Day11_Process(data, i - 1, j - 1)    // left top  
				 + Day11_Process(data, i - 1, j + 1)    // right top
				 + Day11_Process(data, i + 1, j - 1)    // left bottom
				 + Day11_Process(data, i + 1, j + 1);   // right bottom

	return result + 1;
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
