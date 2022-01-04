 #region Day 10
private void Day10_1()
{
	List<string> data = Day10_ReadData();

	int total = 0;
	foreach (string s in data)
	{
		total += Day10_ProcessBroken(s);
	}

	ctrlResult.Text = total.ToString();
}

private void Day10_2()
{
	List<string> data = Day10_ReadData();

	List<long> result = new List<long>();
	int ind = 0;
	foreach (string s in data)
	{
		if (Day10_ProcessBroken(s) == 0)
		{
			long u = Day10_ProcessIncomplete(s);
			if (u > 0) result.Add(u);
		}
		ind++;                    
	}

	result.Sort();

	ctrlResult.Text = result[result.Count / 2].ToString();
}

private long Day10_ProcessIncomplete(string s)
{
	Stack<char> stack = new Stack<char>();
	foreach (char c in s)
	{
		if (c == '(' || c == '[' || c == '{' || c == '<')
			stack.Push(c);
		else
			stack.Pop();
	}

	long result = 0;
	while (stack.Count > 0)
	{
		char c = stack.Pop();
		int unit = 0;
		if (c == '(') unit = 1;
		else if (c == '[') unit = 2;
		else if (c == '{') unit = 3;
		else if (c == '<') unit = 4;

		result = result * 5 + unit;
	}

	return result;

}

private int Day10_ProcessBroken(string s)
{
	Stack<char> stack = new Stack<char>();
	int result = 0;
	foreach (char c in s)
	{
		if (c == '(' || c=='[' || c=='{' || c=='<')
		{
			stack.Push(c);
		}
		else
		{
			char cc = stack.Pop();
			if (c == ')')
			{
				if (cc != '(')
				{
					result = 3;
					break;
				}
			}
			else if (c == ']')
			{
				if (cc != '[')
				{
					result = 57;
					break;
				}
			}
			else if (c == '}')
			{
				if (cc != '{')
				{
					result = 1197;
					break;
				}
			}
			else if (c == '>')
			{
				if (cc != '<')
				{
					result = 25137;
					break;
				}
			}
		}
	}

	return result;
}

private List<string> Day10_ReadData()
{
	List<string> result = new List<string>();
	StreamReader streamReader = new StreamReader("z:\\Projects\\AdventofCode\\Data\\day10_data.txt");
	string value = streamReader.ReadLine();
	while (value != null)
	{
		result.Add(value);

		value = streamReader.ReadLine();
	}
	streamReader.Close();

	return result;
}
#endregion Day 10
