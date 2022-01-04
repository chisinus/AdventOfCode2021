#region Day 5
class Day5_Position
{
	public int X { get; set; }
	public int Y { get; set; }
}

private void Day5_1()
{
	int[] data = Day5_ReadData(false);

	ctrlResult.Text = data.Count(i => i > 1).ToString();
}

private void Day5_2()
{
	int[] data = Day5_ReadData(true);

	ctrlResult.Text = data.Count(i => i > 1).ToString();
}

private int[] Day5_ReadData(bool includeDiagonal)
{
	int[] data = new int[1000000];

	StreamReader streamReader = new StreamReader("z:\\Projects\\AdventofCode\\Data\\day5_data.txt");
	string value = streamReader.ReadLine();
	while (value != null)
	{
		Day5_Position pos1 = Day5_GetPosition(value.Substring(0, value.IndexOf('-') - 1).Trim());
		Day5_Position pos2 = Day5_GetPosition(value.Substring(value.IndexOf('>') + 1).Trim());

		if ((pos1.X == pos2.X) || (pos1.Y == pos2.Y) ||
			(includeDiagonal && (Math.Abs(pos1.X-pos2.X) == Math.Abs(pos1.Y-pos2.Y))))
		{
			List<Day5_Position> positions = new List<Day5_Position>();
			if (pos1.X == pos2.X)
				positions = GetVerticalPositions(pos1, pos2);
			else if (pos1.Y == pos2.Y)
				positions = GetHorizontalPositions(pos1, pos2);
			else if (includeDiagonal)
				positions = GetDiagonalPositions(pos1, pos2);

			foreach (Day5_Position pos in positions)
			{
				data[pos.X * 1000 + pos.Y]++;
			}
		}

		value = streamReader.ReadLine();
	}

	streamReader.Close();

	return data;
}

private List<Day5_Position> GetDiagonalPositions(Day5_Position pos1, Day5_Position pos2)
{
	int xIncremental = (pos1.X < pos2.X) ? 1 : -1;
	int yIncremental = (pos1.Y < pos2.Y) ? 1 : -1;

	List<Day5_Position> result = new List<Day5_Position>();
	int x = pos1.X;
	int y = pos1.Y;
	while (true)
	{
		result.Add(new Day5_Position() { X = x, Y = y });
		if (x == pos2.X) break;

		x += xIncremental;
		y += yIncremental;
	}

	return result;
}

private List<Day5_Position> GetHorizontalPositions(Day5_Position point1, Day5_Position point2)
{
	List<Day5_Position> result = new List<Day5_Position>();
	int start = point1.X <= point2.X ? point1.X : point2.X;
	int end = point1.X <= point2.X ? point2.X : point1.X;
	for (int x=start; x<=end; x++)
	{
		result.Add(new Day5_Position() { X = x, Y = point1.Y });
	}

	return result;
}

private List<Day5_Position> GetVerticalPositions(Day5_Position point1, Day5_Position point2)
{
	List<Day5_Position> result = new List<Day5_Position>();
	int start = point1.Y <= point2.Y ? point1.Y : point2.Y;
	int end = point1.Y <= point2.Y ? point2.Y : point1.Y;
	for (int y = start; y <= end; y++)
	{
		result.Add(new Day5_Position() { X = point1.X, Y = y });
	}

	return result;
}

private Day5_Position Day5_GetPosition(string value)
{
	int ind = value.IndexOf(',');
	int x = int.Parse(value.Substring(0, ind));
	int y = int.Parse(value.Substring(ind + 1));

	return new Day5_Position() { X = x, Y = y };
}
#endregion Day 5
