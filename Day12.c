#region Day 12
class Day12_Data
{
	public string CaveName { get; set; }
	public bool IsLargeCave { get; set; }
	public int Remain { get; set; }

	public List<Day12_Data> Linked { get; set; }

	public Day12_Data(string name)
	{
		CaveName = name;
		IsLargeCave = char.IsUpper(name, 0);
		ResetNumber();
		Linked = new List<Day12_Data>();
	}

	public void ResetNumber()
	{
		Remain = IsLargeCave ? 99999 : 1;
	}
}

List<Day12_Data> Day12Data;
List<Day12_Data> Day12_Path = new List<Day12_Data>();
string Day12_TwicePoint = "";
private void Day12_1()
{
	Day12Data = new List<Day12_Data>();
	Day12_ReadData();

	ctrlResult.Text = Day12_Process1(Day12Data.First(a => a.CaveName == "start")).ToString();
}

private void Day12_2()
{
	Day12Data = new List<Day12_Data>();
	Day12_ReadData();

	ctrlResult.Text = Day12_Process2(Day12Data.First(a => a.CaveName == "start")).ToString();
}

private int Day12_Process1(Day12_Data point)
{
	if (point.Remain == 0)  return 0;

	Day12_Path.Add(point);
	point.Remain--;

	int count = 0;
	foreach (Day12_Data data in point.Linked)
	{
		count += data.CaveName == "end" ? 1 : Day12_Process1(data);
	}

	Day12_Path.RemoveAt(Day12_Path.Count - 1);
	point.ResetNumber();

	return count;
}

private int Day12_Process2(Day12_Data point)
{
	if (point.Remain == 0 && !string.IsNullOrEmpty(Day12_TwicePoint)) return 0;

	Day12_Path.Add(point);
	if (!point.IsLargeCave && string.IsNullOrEmpty(Day12_TwicePoint) && point.CaveName != "start" && point.Remain == 0)
		Day12_TwicePoint = point.CaveName;
	else
		point.Remain--;

	int count = 0;
	foreach (Day12_Data data in point.Linked)
	{
		count += data.CaveName == "end" ? 1 : Day12_Process2(data);
	}

	Day12_Path.RemoveAt(Day12_Path.Count - 1);
	
	if (Day12_TwicePoint == point.CaveName && point.Remain == 0) 
		Day12_TwicePoint = "";
	else 
		point.ResetNumber();

	return count;
}

private void Day12_ReadData()
{
	StreamReader streamReader = new StreamReader("z:\\Projects\\AdventofCode\\Data\\day12_data.txt");
	string value = streamReader.ReadLine();
	while (value != null)
	{
		int ind = value.IndexOf("-");
		string begin = value.Substring(0, ind);
		string end = value.Substring(ind + 1);

		CreatePoint(begin, end);

		value = streamReader.ReadLine();
	}
	streamReader.Close();
}

private void CreatePoint(string begin, string end)
{
	Day12_Data beginPoint = Day12Data.Where(a=>a.CaveName == begin).FirstOrDefault();
	if (beginPoint == null)
	{
		beginPoint = new Day12_Data(begin);
		Day12Data.Add(beginPoint);
	}

	Day12_Data endPoint = Day12Data.Where(a => a.CaveName == end).FirstOrDefault();
	if (endPoint == null)
	{
		endPoint = new Day12_Data(end);
		Day12Data.Add(endPoint);
	}

	if (endPoint.CaveName != "start") beginPoint.Linked.Add(endPoint);
	if (beginPoint.CaveName != "start") endPoint.Linked.Add(beginPoint);
}
#endregion Day 12