struct Account//用户名的账户和密码信息
{
	char UsrName[20];
	char Psword[20];
};

struct PatientInfo//患者信息
{
	Account a;
	double height;
	double weight;

	char phone[20];
	char record[50];

	char Consul[50];//咨询信息
	char Answer[50];//评价反馈

	int flag;//是否有咨询

};
int patientNum=0;//病人数量
PatientInfo pInfo[100];
//加载病人文件
void loadPatient(char *fileName){
	ifstream fin(fileName, ios::in);
	if(!fin)
	{
		cout<<fileName<<"文件信息为空!"<<endl;
		patientNum=0;
		saveToPatientFile(fileName);

	}else{
		fin>>patientNum;
		char temp[20];
		//读取标题
		for(int i=0;i<9;i++){
			fin>>temp;
		}

		for(int i=0;i<patientNum;i++){
			fin>>pInfo[i].a.UsrName;
			fin>>pInfo[i].a.Psword;
			fin>>pInfo[i].height;
			fin>>pInfo[i].weight;
			fin>>pInfo[i].phone;
			fin>>pInfo[i].record;
			fin>>pInfo[i].Consul;
			fin>>pInfo[i].Answer;
			fin>>pInfo[i].flag;
		}

		fin.close();
	}
}

void saveToDoctorFile(char *fileName){


	ofstream fout(fileName);
	fout<<doctorNum<<endl;
	fout<<"用户名 密码 年龄 性别"<<endl;

	for(int i=0;i<doctorNum;i++){
		fout<<dInfo[i].a.UsrName<<" ";
		fout<<dInfo[i].a.Psword<<" ";
		fout<<dInfo[i].age<<" ";
		fout<<dInfo[i].sex<<" ";

		fout<<endl;
	}
	fout.close();
	cout<<"创建新文件成功！"<<endl;

}
//病人注册
void patientRegest(){
	char usrname[20];
	cout << "请输入用户名：";
	cin>>usrname;
	for(int i=0;i<patientNum;i++){
		if(strcmp(usrname,pInfo[i].a.UsrName)==0){
			cout <<"失败，此用户名，已经存在！" << endl;
			return;
		}
	}
	strcpy(pInfo[patientNum].a.UsrName,usrname);

	cout << "请输入密码：";
	cin>>pInfo[patientNum].a.Psword;

	cout << "请输入身高：";
	cin>>pInfo[patientNum].height;

	cout << "请输入体重：";
	cin>>pInfo[patientNum].weight;

	cout << "请输入电话：";
	cin>>pInfo[patientNum].phone;

	cout << "请输入病历记录：";
	cin>>pInfo[patientNum].record;

	strcpy(pInfo[patientNum].Consul,"无");
	strcpy(pInfo[patientNum].Answer,"无");


	usrname,pInfo[patientNum].flag=0;//是否咨询

	patientNum++;

	saveToPatientFile("patient.txt");

	cout << "注册信息成功！"<<endl;

}
void patientMenu(){

	cout << "\n===============================\n";
	cout << "      穿戴者界面\n";
	cout << "      1.基本信息查询\n";
	cout << "      2.实时查询 \n";
	cout << "      3.咨询反馈 \n";
	cout << "      其他.退出系统\n";
	cout << "===============================\n";
	cout <<endl;
	cout << "请输入操作对应的序号 : ";

}
//病人登录
void patientLogin(){
	char usrname[20];
	char psword[20];

	cout << "请输入用户名：";
	cin>>usrname;
	int i;
	for(i=0;i<patientNum;i++){
		if(strcmp(usrname,pInfo[i].a.UsrName)==0){
			break;			
		}
	}

	if(i==patientNum){
		cout <<"失败，没有找到此用户！" << endl;
		return;
	}
	cout<<"密码：";
	cin>>psword;

	if(strcmp(psword,pInfo[i].a.Psword)!=0){
		cout <<"失败，密码错误！" << endl;
		return;			
	}
	int sel,f=1;

	while(f){
		patientMenu();
		cin>>sel;
		switch(sel)
		{
		case 1: 

			inforQuery(i);			
			break;

		case 2: 
			cout<<"监测数据中....\n";
			cout<<"警报装置....\n";					
			break;

		case 3: 
			consulFeedback(i);
			break;

		default:		
			f=0;
		}

	}
}

void showMenu()
{
	cout << "\n===============================\n";
	cout << "      个人健康护理软件系统\n";
	cout << "      1.穿戴者界面\n";
	cout << "      2.医生界面\n";
	cout << "      其他.退出系统\n";
	cout << "===============================\n";
	cout <<endl;
}

void patient(){

	int f=1;
	int sel;


	while(f){
		cout << "      1.登录\n";
		cout << "      2.注册\n";
		cout << "      其他.退出\n";
		cout << "请输入操作对应的序号 : ";

		cin >>sel;

		switch(sel)
		{
		case 1: 
			patientLogin();			
			break;

		case 2: 

			patientRegest();		
			break;

		default:
			cout<<"\n回归主界面！";
			f=0;
		}
	}
}
void doctorRegest(){
	char usrname[20];
	cout << "请输入用户名：";
	cin>>usrname;
	for(int i=0;i<doctorNum;i++){
		if(strcmp(usrname,dInfo[i].a.UsrName)==0){
			cout <<"失败，此用户名，已经存在！" << endl;
			return;
		}
	}
	strcpy(dInfo[doctorNum].a.UsrName,usrname);

	cout << "请输入密码：";
	cin>>dInfo[doctorNum].a.Psword;

	cout << "请输入年龄：";
	cin>>dInfo[doctorNum].age;

	cout << "请输入性别：";
	cin>>dInfo[doctorNum].sex;

	doctorNum++;

	saveToDoctorFile("doctor.txt");

	cout << "注册信息成功！"<<endl;
}	
void doctorMenu(){
	cout << "\n===============================\n";
	cout << "      医生界面\n";
	cout << "      1.医生基本信息\n";
	cout << "      2.在线诊断 \n";
	cout << "      其它.退出系统\n";
	cout << "===============================\n";
	cout <<endl;
	cout << "请输入操作对应的序号 : ";
}

