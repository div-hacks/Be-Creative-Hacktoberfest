//Given an integer, convert it to a roman numeral.


class Solution
{

public:
  string intToRoman (int num)
  {


    map < int, string, greater < int >>m;

      m[1] = "I";

      m[5] = "V";

      m[10] = "X";

      m[50] = "L";

      m[100] = "C";

      m[500] = "D";

      m[1000] = "M";

      m[4] = "IV";

      m[9] = "IX";

      m[40] = "XL";

      m[90] = "XC";

      m[400] = "CD";

      m[900] = "CM";

    int temp = num;
    string s = "";

    for (auto i:m)

      {

	if (temp >= i.first)

	  {

	    int f = temp / i.first;

	      temp -= i.first * f;


	    while (f--)

	      {

		s += i.second;


	      }

	  }

      }

    return s;

  }

};
