#region Day 8
private void Day8_1()
{
	List<string> data = Day8_ReadData();

	int total = 0;
	foreach (string s in data)
	{
		string second = s.Substring(s.IndexOf("|")+1).Trim();
		string [] values = second.Split(' ');
		foreach (string v in values)
		{
			switch (v.Length)
			{
				case 2:
				case 7:
				case 3:
				case 4:
					total++;
					break;
			}
		}
	}

	ctrlResult.Text = total.ToString();
}

private void Day8_2()
{
	List<string> data = Day8_ReadData();

	int total = 0;
	foreach (string s in data)
	{
		string[] codes = FindNumber(s);

		string second = s.Substring(s.IndexOf("|") + 1).Trim();
		string[] values = second.Split(' ');
		string sValue = "";
		foreach (string v in values)
		{
			string sorted = String.Concat(v.OrderBy(c => c));
			sValue += Array.FindIndex(codes, a=>a==sorted).ToString();
		}

		total += Convert.ToInt32(sValue);

	}

	ctrlResult.Text = total.ToString();
}

private string[] FindNumber(string s)
{
	char[] segments = new char[7];

	string[] values = s.Substring(0, s.IndexOf("|")).Trim().Split(' ');
	// 1
	string s1 = values.Where(a => a.Length == 2).First();
	// 7 find top
	segments[0] = values.Where(a => a.Length == 3).First().Except(s1).First();
	// 4
	string s4 = values.Where(a => a.Length == 4).First();
	// 8 
	string s8 = values.Where(a => a.Length == 7).First();
	// 6
	string s6 = values.Where(a => a.Length == 6 
								  && (a.IndexOf(s1[0]) == -1 || a.IndexOf(s1[1]) == -1)).First();
	segments[2] = (s6.IndexOf(s1[0]) < 0) ? s1[0] : s1[1];
	segments[5] = (s6.IndexOf(s1[0]) < 0) ? s1[1] : s1[0];
	// 9
	string s147 = s1 + s4 + segments[0];
	string s9 = values.Where(a => (a.Length == 6) && (a.Except(s147).Count() == 1)).First();
	segments[6] = s9.Except(s147).First();
	// 3
	string s0257 = "" + segments[0] + segments[2] + segments[5] + segments[6];
	string s3 = values.Where(a => (a.Length == 5) && (a.Except(s0257).Count() == 1)).First();
	segments[3] = s3.Except(s0257).First();
	// 2
	string s0236 = "" + segments[0] + segments[2] + segments[3] + segments[6];
	string s2 = values.Where(a => (a.Length == 5) && (a.Except(s0236).Count() == 1) && (a!=s3)).First();
	segments[4] = s2.Except(s0236).First();
	// 5
	string sFull = "abcdefg";
	string s023456 = " " + segments[0] + segments[2] + segments[3] + segments[4] + segments[5] + segments[6];
	segments[1] = sFull.Except(s023456).First();

	string[] result = new string[10];
	result[0] = String.Concat(("" + segments[0] + segments[1] + segments[2] + segments[4] + segments[5] + segments[6]).OrderBy(c => c));
	result[1] = String.Concat(("" + segments[2] + segments[5]).OrderBy(c => c)); ;
	result[2] = String.Concat(("" + segments[0] + segments[2] + segments[3] + segments[4] + segments[6]).OrderBy(c => c)); ;
	result[3] = String.Concat(("" + segments[0] + segments[2] + segments[3] + segments[5] + segments[6]).OrderBy(c => c)); ;
	result[4] = String.Concat(("" + segments[1] + segments[2] + segments[3] + segments[5]).OrderBy(c => c)); ;
	result[5] = String.Concat(("" + segments[0] + segments[1] + segments[3] + segments[5] + segments[6]).OrderBy(c => c)); ;
	result[6] = String.Concat(("" + segments[0] + segments[1] + segments[3] + segments[4] + segments[5] + segments[6]).OrderBy(c => c)); ;
	result[7] = String.Concat(("" + segments[0] + segments[2] + segments[5]).OrderBy(c => c)); ;
	result[8] = String.Concat(("" + segments[0] + segments[1] + segments[2] + segments[3] + segments[4] + segments[5] + segments[6]).OrderBy(c => c)); ;
	result[9] = String.Concat(("" + segments[0] + segments[1] + segments[2] + segments[3] + segments[5] + segments[6]).OrderBy(c => c)); ;

	return result;
}

private List<string> Day8_ReadData()
{
	List<string> result = new List<string>();
	StreamReader streamReader = new StreamReader("z:\\Projects\\AdventofCode\\Data\\day8_data.txt");
	string value = streamReader.ReadLine();
	while (value != null)
	{
		result.Add(value);
		value = streamReader.ReadLine();
	}
	streamReader.Close();

	return result;
}
#endregion Day 8