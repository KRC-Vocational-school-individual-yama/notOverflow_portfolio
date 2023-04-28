#include<iostream>
#include<string>
#include<vector>

class OverFlow {
public:
	OverFlow()
		:value()
	{
		value.clear();
	}
	OverFlow(std::string val) {
		value.clear();
		this->set(val);
	}

	std::vector<int> GetValue() { return value; }

	void set(std::string val) {
		 int loop=val.size() / 5;
		 if (loop <= 0) {
			 value.emplace_back(std::stoi(val));
			 return;
		 }
		 for (int i = 0; i < loop; i++) {

				std::string str= val.substr(0,5);
				value.emplace_back(std::stoi(str));

				val = val.substr(5);

				//str;
			 
		 }

	}

	std::string add(OverFlow num) {
		std::vector<int> val = num.GetValue();

		int valuSize= val.size();
		int mySize = value.size();

		int loopNum = 0;
		if (valuSize > mySize)
			loopNum = valuSize;
		else
			loopNum = mySize;

		std::vector<int> ans;
		ans.resize(loopNum,0);

		for (int i = 0; i < loopNum; i++) {
			if (val.size() > i && value.size() > i) {
				ans.at(i) = value.at(i) + val.at(i);
			}
			else {
				if (valuSize > mySize)
					ans.at(i) += val.at(i);
				else
					ans.at(i) += value.at(i);

			}
		}
		for (int i = 0; i < loopNum; i++) {

			double calc= (double)ans.at(i)/100000.0;
			if ((int)calc > 0) {
				int index = i + 1;
				if (index < loopNum) 
					ans.at(index) += (int)calc;
				else{
					ans.emplace_back((int)calc);
				}
				ans.at(i)-= (int)calc * 100000;
			}
		}

		value = ans;

		return "";
	}

	//Ž©•ª‚ª‘å‚«‚©‚Á‚½‚ç 1
	//ˆø”‚ª‘å‚«‚©‚Á‚½‚ç 2
	//‚Ç‚¿‚ç‚Å‚à‚È‚¢@     3
	int comparison(OverFlow num) {
		bool falg = false;
		std::vector<int> val = num.GetValue();
		if (val.size() > value.size()) {
			return 2;
		}
		else if (val.size() < value.size()){
			return 1;
		}

		for (int i = val.size()-1; i >= 0; i--) {
			int other = val.at(i);
			int my = value.at(i);
			if (other >my) {
				return 2;
			}
			else if (other < my) {
				return 1;
			}
		}

		return 3;
	}

	std::string disp(bool disp=true) {
		std::string str="";

		std::vector<std::string>strs;
		strs.clear();
		for (int i = 0; i < value.size(); i++) {
			strs.emplace_back(std::to_string( value.at(i)));
		}

		for (int i = 0; i < strs.size(); i++) {
			int index = i + 1;
			if (index >= strs.size())continue;

			int zeroNum = 5-strs.at(i).size();
			std::string zero = "";
			for (int i = 0; i < zeroNum; i++) {
				zero += "0";
			}

			strs.at(i) = zero+ strs.at(i);
		}

		for (auto it = strs.rbegin(); it != strs.rend(); it++) {
			int num = std::stoi( (*it));

			std::cout << (*it);
			str += (*it);
		}

		//for (auto it = value.rbegin(); it != value.rend(); it++) {
		//	int num = (*it);
		//
		//	std::cout << num ;
		//	str+= std::to_string(num);
		//}

		/*for (auto num : value) {
			if(disp)
			std::cout << num;
			str += std::to_string(num);
		}*/
		if (disp)
			std::cout<< std::endl ;
		 return str;
	}
	

private:
	std::vector<int>value;
};

int main() {
	//OverFlow temp;
	//temp.set("1234567890333333333333333333333333333333333333333333333");
	//std::string str= temp.disp();

	OverFlow num1("1");
	OverFlow num2("1");

	num1.disp();
	num2.disp();
	//OverFlow temp ;
	for (int i = 0; i < 1000-2; i++) {
		std::cout << i << "‰ñ–Ú@@";
		//num1.add(num2);
		i=i;
		int patternNum = num1.comparison(num2);
		switch (patternNum){
		case 1:
			num2.add(num1);

			num2.disp();
			break;
		case 2:
			num1.add(num2);

			num1.disp();
			break;
		case 3:
			num1.add(num2);

			num1.disp();
			break;
		default:
			std::cout << std::endl;
			std::cout << "error : " << std::endl;
			break;
		}

	}

	
}


