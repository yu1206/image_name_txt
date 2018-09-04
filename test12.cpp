  #include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc_c.h"
#include "fstream"
#include <direct.h>
#include <io.h>
#include <Windows.h>

 using namespace std;
using namespace cv;

 extern int readDir(char *dirName, vector<string> &filesName);



int test12(int argc, char *argv[])
{
		 
	//string name="LargeTruckRestriction";
   // string name="NoPlate";
	// string name="NotShenZhenVehicle";
	//string name="PlateChineseBlur";
	//string name="PlateRecognitionError";
	 string name="UseIncorrectLane";

	string inputPath="I:/harzone-police/huawei/"+name;
	string outputTXT="I:/harzone-police/huawei/"+name+"/0.txt";
	fstream if_txt(outputTXT,ios::out);
	if(!if_txt.is_open())
	{
		cout << "文件数据打开错误！"<< endl;
		system("pause");
		return false;
	}
	vector<string> v_img_;
	readDir((char*)inputPath.c_str(), v_img_);
	for(int i=0;i<v_img_.size();i++)
	{
		int npos = v_img_[i].find_last_of('/');
		int npos2 = v_img_[i].find_last_of('.');
		string name1 = v_img_[i].substr(npos + 1, npos2 - npos - 1);
		npos = name1.find_last_of('-');
		string plateName=name1.substr(npos+1,name1.size()-npos);
		name1=name1.substr(0,npos-1);
		if_txt<<name1<<" "<<plateName<<endl;
	}
	if_txt.close();
	return 0;
}
