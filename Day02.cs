#region Day 2
private void Day2_1()
{
	int h = 0;
	int d = 0;

	StreamReader streamReader = new StreamReader("z:\\Projects\\AdventofCode\\Data\\day2_data.txt");
	string value = streamReader.ReadLine();
	while (value != null)
	{
		if (value.IndexOf("up") == 0)
		{
			d -= int.Parse(value.Substring(2).Trim());
		}
		else if (value.IndexOf("down") == 0)
		{
			d += int.Parse(value.Substring(4).Trim());
		}
		else
		{
			h += int.Parse(value.Substring(7).Trim());
		}

		value = streamReader.ReadLine();
	}

	streamReader.Close();

	ctrlResult.Text = (d * h).ToString();
}
private void Day2_2()
{
	int h = 0;
	int d = 0;
	int factor = 0;

	StreamReader streamReader = new StreamReader("z:\\Projects\\AdventofCode\\Data\\day2_data.txt");
	string value = streamReader.ReadLine();
	while (value != null)
	{
		if (value.IndexOf("up") == 0)
		{
			factor -= int.Parse(value.Substring(2).Trim());
		}
		else if (value.IndexOf("down") == 0)
		{
			factor += int.Parse(value.Substring(4).Trim());
		}
		else
		{
			int i = int.Parse(value.Substring(7).Trim());
			h += i;
			d += factor * i;
		}

		value = streamReader.ReadLine();
	}

	streamReader.Close();

	ctrlResult.Text = (d * h).ToString();
}
#endregion Day 2
