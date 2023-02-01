/*
	Name: Shubham Sarang
	Roll no: 1345
	Unit: Trees
	Program: Graph
*/


int main()
{
	int ch;
	while(1)
	{
		system("cls");
		cout<<"***GRAPH*** \n\n";
		
		cout<<"1. Build Heap \n";
		cout<<"2. Insert Heap \n";
		cout<<"3. Display \n";
		cout<<"4. Delete \n";
		cout<<"5. Exit \n";
		
		cout<<"Enter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"Build heap: ";
				getch();
				break;
			case 2:
				cout<<"Insert heap: ";
				getch();
				break;
			case 3:
				cout<<"";
				getch();
				break;
			case 4:
				cout<<"";
				getch();
				break;
			case 5:
				exit(1);
				break;
			default:
				cout<<"Wrong opt bruv";
				getch();
				break;		
		}//end switch
	}//end while
}//end main
