#region Day 9
private void Day9_1()
{
	int[][] data = Day9_ReadData();

	int total = 0;
	for (int i=0; i<data.Length; i++)
	{
		for (int j=0; j<data[i].Length; j++)
		{
			if (Day9_IsLowest(data, i, j))
				total += data[i][j] + 1;
		}
	}

	ctrlResult.Text = total.ToString();
}

private void Day9_2()
{
	int[][] data = Day9_ReadData();

	List<int> basins = new List<int>();
	for (int i = 0; i < data.Length; i++)
	{
		for (int j = 0; j < data[i].Length; j++)
		{
			if (Day9_IsLowest(data, i, j))
			{
				basins.Add(Day9_FindBasin(data, i, j));
			}
		}
	}

	basins.Sort();
	long result = basins[basins.Count - 1] *
				 ((basins.Count > 1) ? basins[basins.Count - 2] : 1) *
				 ((basins.Count > 2) ? basins[basins.Count - 3] : 1);

	ctrlResult.Text = result.ToString();
}

private int Day9_FindBasin(int[][] data, int i, int j)
{
	if (data[i][j] == 9) return 0;

	data[i][j] = 9; // processed

	// the logic does not check slope direction
	bool left = Day9_GetCellValue(data, i, j - 1) == -1 ? false : (data[i][j - 1] != 9);// && data[i][j-1] > data[i][j];
	bool top = Day9_GetCellValue(data, i - 1, j) == -1 ? false : (data[i - 1][j] != 9);// && data[i-1][j] > data[i][j];
	bool right = Day9_GetCellValue(data, i, j + 1) == -1 ? false : (data[i][j + 1] != 9);// && data[i][j+1] > data[i][j];
	bool bottom = Day9_GetCellValue(data, i + 1, j) == -1 ? false : (data[i + 1][j] != 9);//&& data[i+1][j] > data[i][j];

	int result = 0;
	if (left) result += Day9_FindBasin(data, i, j-1);
	if (top) result += Day9_FindBasin(data, i-1, j);
	if (right) result += Day9_FindBasin(data, i, j+1);
	if (bottom) result += Day9_FindBasin(data, i+1, j);

	return result + 1;
}

private int Day9_GetCellValue(int[][] data, int i, int j)
{
	if ((i < 0) || (j < 0) || (i == data.Length) || (j == data[i].Length))
		return -1;

	return data[i][j];
}

private bool Day9_IsLowest(int[][] data, int i, int j)
{
	return (i == 0 || data[i - 1][j] > data[i][j]) && // top
			(j == data[i].Length - 1 || data[i][j] < data[i][j + 1]) && // rigth
			(i == data.Length - 1 || data[i][j] < data[i + 1][j]) && // bottom
			(j == 0 || data[i][j] < data[i][j - 1]);   // left;
}

private int [][] Day9_ReadData()
{
	List<int[]> result = new List<int[]>();
	StreamReader streamReader = new StreamReader("z:\\Projects\\AdventofCode\\Data\\day9_data.txt");
	string value = streamReader.ReadLine();
	while (value != null)
	{
		int[] data = new int[value.Length];
		for (int i=0; i<value.Length; i++)
		{
			data[i] = Convert.ToInt32(value.Substring(i, 1));
		}

		result.Add(data);

		value = streamReader.ReadLine();
	}
	streamReader.Close();

	return result.ToArray();
}
#endregion Day 9