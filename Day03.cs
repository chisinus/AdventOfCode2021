#region Day 3
private void Day3_1()
{
	StreamReader streamReader = new StreamReader("z:\\Projects\\AdventofCode\\Data\\day3_data.txt");
	string value = streamReader.ReadLine();
	int count = 0;
	int[] total1 = new int[value.Length];
	while (value != null)
	{
		count++;
		for (int i=0; i<value.Length; i++)
		{
			if (value[i] - '0' == 1)
				total1[i]++;
		}

		value = streamReader.ReadLine();
	}

	streamReader.Close();

	string gamma = "";
	string epsilon = "";
	int half = count / 2;
	for (int i=0; i<total1.Length; i++)
	{
		if (total1[i] > half)
		{
			gamma += 1;
			epsilon += 0;
		}
		else
		{
			{
				gamma += 0;
				epsilon += 1;
			}
		}
	}

	int g = Convert.ToInt32(gamma, 2);
	int e = Convert.ToInt32(epsilon, 2);
	
	ctrlResult.Text = (g * e).ToString();
}
private void Day3_2()
{
	StreamReader streamReader = new StreamReader("z:\\Projects\\AdventofCode\\Data\\day3_data.txt");
	string value = streamReader.ReadLine();
	List<char[]> values = new List<char[]>();
	while (value != null)
	{
		values.Add(value.ToCharArray());

		value = streamReader.ReadLine();
	}

	streamReader.Close();

	string oxygen = new string(Day3_CalculateMost(values, 0)[0]);
	string co2 = new string(Day3_CalculateLeast(values, 0)[0]);

	int g = Convert.ToInt32(oxygen, 2);
	int e = Convert.ToInt32(co2, 2);

	ctrlResult.Text = (g * e).ToString();
}

private List<char[]> Day3_CalculateMost(List<char[]> values, int pos)
{
	if (values.Count == 1) return values;

	int count1 = 0;
	for (int j=0; j<values.Count; j++)
	{
		if (values[j][pos] == '1') count1++; 
	}

	int half = values.Count / 2;
	if (values.Count % 2 == 1)
		half++;

	var result = values.Where(arr=>arr[pos] == ((count1 >= half)?'1':'0')).ToList();

	return Day3_CalculateMost(result, ++pos);
}

private List<char[]> Day3_CalculateLeast(List<char[]> values, int pos)
{
	if (values.Count == 1) return values;

	int count1 = 0;
	for (int j = 0; j < values.Count; j++)
	{
		if (values[j][pos] == '1') count1++;
	}

	int half = values.Count / 2;
	if (values.Count % 2 == 1)
		half++;

	var result = values.Where(arr => arr[pos] == ((count1 < half) ? '1' : '0')).ToList();

	return Day3_CalculateLeast(result, ++pos);
}
#endregion Day 3
