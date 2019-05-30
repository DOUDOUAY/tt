struct Account//�û������˻���������Ϣ
{
	char UsrName[20];
	char Psword[20];
};

struct PatientInfo//������Ϣ
{
	Account a;
	double height;
	double weight;

	char phone[20];
	char record[50];

	char Consul[50];//��ѯ��Ϣ
	char Answer[50];//���۷���

	int flag;//�Ƿ�����ѯ

};
int patientNum=0;//��������
PatientInfo pInfo[100];
//���ز����ļ�
void loadPatient(char *fileName){
	ifstream fin(fileName, ios::in);
	if(!fin)
	{
		cout<<fileName<<"�ļ���ϢΪ��!"<<endl;
		patientNum=0;
		saveToPatientFile(fileName);

	}else{
		fin>>patientNum;
		char temp[20];
		//��ȡ����
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
	fout<<"�û��� ���� ���� �Ա�"<<endl;

	for(int i=0;i<doctorNum;i++){
		fout<<dInfo[i].a.UsrName<<" ";
		fout<<dInfo[i].a.Psword<<" ";
		fout<<dInfo[i].age<<" ";
		fout<<dInfo[i].sex<<" ";

		fout<<endl;
	}
	fout.close();
	cout<<"�������ļ��ɹ���"<<endl;

}
//����ע��
void patientRegest(){
	char usrname[20];
	cout << "�������û�����";
	cin>>usrname;
	for(int i=0;i<patientNum;i++){
		if(strcmp(usrname,pInfo[i].a.UsrName)==0){
			cout <<"ʧ�ܣ����û������Ѿ����ڣ�" << endl;
			return;
		}
	}
	strcpy(pInfo[patientNum].a.UsrName,usrname);

	cout << "���������룺";
	cin>>pInfo[patientNum].a.Psword;

	cout << "��������ߣ�";
	cin>>pInfo[patientNum].height;

	cout << "���������أ�";
	cin>>pInfo[patientNum].weight;

	cout << "������绰��";
	cin>>pInfo[patientNum].phone;

	cout << "�����벡����¼��";
	cin>>pInfo[patientNum].record;

	strcpy(pInfo[patientNum].Consul,"��");
	strcpy(pInfo[patientNum].Answer,"��");


	usrname,pInfo[patientNum].flag=0;//�Ƿ���ѯ

	patientNum++;

	saveToPatientFile("patient.txt");

	cout << "ע����Ϣ�ɹ���"<<endl;

}
void patientMenu(){

	cout << "\n===============================\n";
	cout << "      �����߽���\n";
	cout << "      1.������Ϣ��ѯ\n";
	cout << "      2.ʵʱ��ѯ \n";
	cout << "      3.��ѯ���� \n";
	cout << "      ����.�˳�ϵͳ\n";
	cout << "===============================\n";
	cout <<endl;
	cout << "�����������Ӧ����� : ";

}
//���˵�¼
void patientLogin(){
	char usrname[20];
	char psword[20];

	cout << "�������û�����";
	cin>>usrname;
	int i;
	for(i=0;i<patientNum;i++){
		if(strcmp(usrname,pInfo[i].a.UsrName)==0){
			break;			
		}
	}

	if(i==patientNum){
		cout <<"ʧ�ܣ�û���ҵ����û���" << endl;
		return;
	}
	cout<<"���룺";
	cin>>psword;

	if(strcmp(psword,pInfo[i].a.Psword)!=0){
		cout <<"ʧ�ܣ��������" << endl;
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
			cout<<"���������....\n";
			cout<<"����װ��....\n";					
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
	cout << "      ���˽����������ϵͳ\n";
	cout << "      1.�����߽���\n";
	cout << "      2.ҽ������\n";
	cout << "      ����.�˳�ϵͳ\n";
	cout << "===============================\n";
	cout <<endl;
}

void patient(){

	int f=1;
	int sel;


	while(f){
		cout << "      1.��¼\n";
		cout << "      2.ע��\n";
		cout << "      ����.�˳�\n";
		cout << "�����������Ӧ����� : ";

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
			cout<<"\n�ع������棡";
			f=0;
		}
	}
}
void doctorRegest(){
	char usrname[20];
	cout << "�������û�����";
	cin>>usrname;
	for(int i=0;i<doctorNum;i++){
		if(strcmp(usrname,dInfo[i].a.UsrName)==0){
			cout <<"ʧ�ܣ����û������Ѿ����ڣ�" << endl;
			return;
		}
	}
	strcpy(dInfo[doctorNum].a.UsrName,usrname);

	cout << "���������룺";
	cin>>dInfo[doctorNum].a.Psword;

	cout << "���������䣺";
	cin>>dInfo[doctorNum].age;

	cout << "�������Ա�";
	cin>>dInfo[doctorNum].sex;

	doctorNum++;

	saveToDoctorFile("doctor.txt");

	cout << "ע����Ϣ�ɹ���"<<endl;
}	
void doctorMenu(){
	cout << "\n===============================\n";
	cout << "      ҽ������\n";
	cout << "      1.ҽ��������Ϣ\n";
	cout << "      2.������� \n";
	cout << "      ����.�˳�ϵͳ\n";
	cout << "===============================\n";
	cout <<endl;
	cout << "�����������Ӧ����� : ";
}

