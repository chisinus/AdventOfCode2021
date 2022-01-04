#region Day 4
class Day4_Data
{
	public int Number { get; set; }
	public bool Marked { get; set; }
}

class Day4_Block
{
	public Day4_Data[,] Block { get; set; }
	public bool Marked { get; set; }
	public bool Bingoed { get; set; }

	public Day4_Block()
	{
		Block = new Day4_Data[5, 5];
		Marked = false;
		Bingoed = false;
	}

	public int Day4_Bingo(int number, bool check)
	{
		if (Bingoed) return 0;

		int result = 0;
		for (int i =0; i<5; i++)
		{
			for (int j=0; j<5; j++)
			{
				if (Block[i,j].Number == number)
				{
					Block[i, j].Marked = true;
					if (check && (Day4_CheckRow(j) || Day4_CheckColumn(i)))
					{
						int sum = 0;
						for (int i1=0; i1<5; i1++)
						{
							for (int j1=0; j1<5; j1++)
							{
								if (!Block[i1, j1].Marked) sum += Block[i1, j1].Number;
							}
						}

						result = sum * number;
						break;
					}

				}
			}

			if (result > 0) break;
		}

		if (result > 0) Bingoed = true;

		return result;
	}

	private bool Day4_CheckRow(int col)
	{
		bool result = true;
		for (int row = 0; row < 5; row++)
		{
			if (!Block[row, col].Marked)
			{
				result = false;
				break;
			}
		}

		return result;
	}

	private bool Day4_CheckColumn(int row)
	{
		bool result = true;
		for (int col = 0; col < 5; col++)
		{
			if (!Block[row, col].Marked)
			{
				result = false;
				break;
			}
		}

		return result;
	}
}

List<Day4_Block> day4_blocks;
string[] day4_drawNumbers;
private void Day4_1()
{
	Day4_ReadData();

	int result = 0;
	for (int i=0; i<day4_drawNumbers.Length; i++)
	{
		foreach (Day4_Block block in day4_blocks)
		{
			result = block.Day4_Bingo(int.Parse(day4_drawNumbers[i]), i >= 4);
			if (result > 0) break;
		}

		if (result > 0) break;
	}

	ctrlResult.Text = result.ToString();
}

private void Day4_2()
{
	Day4_ReadData();

	int winnerNumber = 0;
	for (int i = 0; i < day4_drawNumbers.Length; i++)
	{
		foreach (Day4_Block block in day4_blocks)
		{
			int result = block.Day4_Bingo(int.Parse(day4_drawNumbers[i]), i >= 4);
			if (result > 0)
			{
				winnerNumber = result;
			}
		}
	}

	ctrlResult.Text = winnerNumber.ToString();
}

private void Day4_ReadData()
{
	day4_blocks = new List<Day4_Block>();
	int index = 0;
	Day4_Block block = new Day4_Block();

	StreamReader streamReader = new StreamReader("z:\\Projects\\AdventofCode\\Data\\day4_data.txt");
	string value = streamReader.ReadLine();
	day4_drawNumbers = value.Split(',');
	_ = streamReader.ReadLine();    // row 2
	value = streamReader.ReadLine();
	while (true)
	{
		value = value.Trim().Replace("  ", " ");

		string[] values = value.Split(' ');
		for (int i = 0; i < 5; i++)
		{
			block.Block[index, i] = new Day4_Data() { Number = int.Parse(values[i]), Marked = false };
		}

		value = streamReader.ReadLine();
		if (value == null) break;

		if (value.Trim() == "")
		{
			day4_blocks.Add(block);
			block = new Day4_Block();
			index = 0;
			value = streamReader.ReadLine();
		}
		else
		{
			index++;
		}
	}

	day4_blocks.Add(block);

	streamReader.Close();
}
#endregion Day 4
