#region Day 13
// TheSameTrain mentioned ValueTuple in my Day 11 Reddit post. I used ValueTuple today.
List<(int X, int Y)> Day13_Points;
List<(char Direction, int Number)> Day13_Instructions;
private void Day13_1()
{
	Day13_ReadData();

	// fold once
	Day13_Instructions = new List<(char Direction, int Number)>() { (Day13_Instructions[0].Direction, Day13_Instructions[0].Number) };

	Day13_Fold();

	ctrlResult.Text = Day13_Points.Count.ToString();
}

private void Day13_2()
{
	Day13_ReadData();
	
	Day13_Fold();

	int maxX = Day13_Points.Select(a => a.X).Max();
	int maxY = Day13_Points.Select(b => b.Y).Max();
	string[,] canvas = new string[maxX + 1, maxY + 1];

	// Draw
	for (int i = 0; i < Day13_Points.Count; i++)
	{
		canvas[Day13_Points[i].X, Day13_Points[i].Y] = "*";
	}

	// Print
	for (int y = 0; y < canvas.GetLength(1); y++)
	{
		for (int x = 0; x < canvas.GetLength(0); x++)
		{
			Debug.Write((canvas[x, y] == null) ? " " : canvas[x, y]);
		}
		Debug.WriteLine("");
	}
}

private void Day13_Fold()
{
	foreach ((char Direction, int Number) instruction in Day13_Instructions)
	{
		if (instruction.Direction == 'x')
		{
			for (int i = 0; i < Day13_Points.Count; i++)
			{
				if (Day13_Points[i].X > instruction.Number)
					Day13_Points[i] = (instruction.Number - (Day13_Points[i].X - instruction.Number), Day13_Points[i].Y);
			}
		}
		else // Y
		{
			for (int i = 0; i < Day13_Points.Count; i++)
			{
				if (Day13_Points[i].Y > instruction.Number)
					Day13_Points[i] = (Day13_Points[i].X, instruction.Number - (Day13_Points[i].Y - instruction.Number));
			}
		}
	}

	Day13_Points = Day13_Points.Distinct().ToList();
}

private void Day13_ReadData()
{
	Day13_Points = new List<(int X, int Y)>();
	Day13_Instructions = new List<(char Direction, int Number)>();

	StreamReader streamReader = new StreamReader("z:\\Projects\\AdventofCode\\Data\\day13_data.txt");
	string value = streamReader.ReadLine();
	// read points
	while (!string.IsNullOrEmpty(value))
	{
		int ind = value.IndexOf(",");
		int x = Convert.ToInt32(value.Substring(0, ind));
		int y = Convert.ToInt32(value.Substring(ind + 1));

		Day13_Points.Add((x, y));

		value = streamReader.ReadLine();
	}

	// read instructions
	value = streamReader.ReadLine();
	while (value != null)
	{
		char direction = value[11];
		int number = Convert.ToInt32(value.Substring(13));

		Day13_Instructions.Add((direction, number));

		value = streamReader.ReadLine();
	}

	streamReader.Close();
}
#endregion Day 13
