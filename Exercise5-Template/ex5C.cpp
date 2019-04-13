#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Record {
  string name;
  string mobile; 
};

void AddRecord(vector<Record> &addressbook) {
  addressbook.resize(addressbook.size()+1);
  cout << "輸入名字" <<endl;
  cin >> addressbook[addressbook.size()-1].name;
  cout << "輸入手機" <<endl;
  cin >> addressbook[addressbook.size()-1].mobile;
}

void ShowRecords(const vector<Record> &addressbook) {
  for(int i=0; i< addressbook.size(); i++){
    cout << ' ' << addressbook[i].name <<'\t'<< addressbook[i].mobile<<endl;
  }
}

void ClearRecords(vector<Record> &addressbook) {
  addressbook.clear();
}

int main() {
  vector<Record> addressbook;
  Record init_data[3] = {
      { "Lee",   "0912345678" },
      { "Huang", "0933112345" },
      { "Liu",   "0944112233" } };
  for (int i = 0; i < 3; ++i) { 
    addressbook.push_back(init_data[i]); 
  }

  bool quit = false;
  while (!quit) {
    cout << "1] 新增資料"     << endl
         << "2] 顯示所有資料" << endl
        <<  "3] 清除所有資料" << endl 
         << "4] 結束程式"     << endl
         << "請輸入你的選擇: ";
    int choice;
    cin  >> choice;
    switch(choice) {
      case 1: AddRecord(addressbook); break;
      case 2: ShowRecords(addressbook); break;
      case 3: ClearRecords(addressbook); break; 
      case 4: quit = true; break;
    } 
  } 
  return 0;
}
