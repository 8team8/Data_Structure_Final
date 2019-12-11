#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <map>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int glob = 0; 
int global = 10;


class domestic_Reserve // 국내예약 클래스 (안유성)
{
protected:
   int flight_numbering;
   char fly_destination[10], to_journey_destination[7],
      to_journey_time[7]; 
   long int date_of_journey;
   int choice, source, destination;

public:
   void d_flight_numbering() {
      glob++;
      flight_numbering = glob;
   }
   int input_the_journey() // 함수 선언 및 정의(국내)
   {
      cout << "\n이동할 날짜를 입력해주세요.(DDMMYY)."<< " 올바른 값을 입력해주세요. " ;
      cin >> date_of_journey;
      cout << "1.부산(1) \t2.김포(2) \t3.서울(3) \t4.인천(4)"<< endl<< endl;
      cout << "출발지를 입력해주세요. ";
      cin >> source;
      cout << "목적지를 입력해주세요. ";
      cin >> destination;
      if ((source == 1 && destination == 2) ||(source == 2 && destination == 1)) 
      {
         cout << "\t \t \t항공 정보" << endl << endl;
         cout << "항공사:\t출발시각:\t도착시각:\t가격:\t\t분류:\n";
         cout << "1.아시아나(1)\t08:00\t\t11:05\t\t70,000\t\t환불가능\n";
         cout << "2.대한항공(2)\t14:00\t\t17:05\t\t65,000\t\t환불가능\n";
         cout << "3.제주에어(3)\t19:00\t\t22:05\t\t80,000\t\t환불가능\n";
      }

      else if ((source == 1 && destination == 3) ||
         (source == 3 && destination == 1))
      {
         cout << "\t \t \t항공 정보" << endl << endl;
         cout << "항공사:\t출발시각:\t도착시각:\t가격:\t\t분류:\n";
         cout << "1.아시아나(1)\t08:00\t\t11:05\t\t90,000\t\t환불가능\n";
         cout << "2.대한항공(2)\t14:00\t\t17:05\t\t85,000\t\t환불가능\n";
         cout << "3.제주에어(3)\t19:00\t\t22:05\t\t60,000\t\t환불가능\n";
      }

      else if ((source == 1 && destination == 4) ||
         (source == 4 && destination == 1)) 
      {
         cout << "\t \t \t항공 정보" << endl << endl;
         cout << "항공사:\t출발시각:\t도착시각:\t가격:\t\t분류:\n";
         cout << "1.아시아나(1)\t08:00\t\t11:05\t\t40,000\t\t환불가능\n";
         cout << "2.대한항공(2)\t14:00\t\t17:05\t\t42,500\t\t환불가능\n";
         cout << "3.제주에어(3)\t19:00\t\t22:05\t\t61,000\t\t환불가능\n";
      }

      else if ((source == 2 && destination == 3) ||
         (source == 3 && destination == 2)) 
      {
         cout << "\t \t \t항공 정보" << endl << endl;
         cout << "항공사:\t출발시각:\t도착시각:\t가격:\t\t분류:\n";
         cout << "1.아시아나(1)\t08:00\t\t11:05\t\t54,000\t\t환불가능\n";
         cout << "2.대한항공(2)\t14:00\t\t17:05\t\t25,000\t\t환불가능\n";
         cout << "3.제주에어(3)\t19:00\t\t22:05\t\t28,900\t\t환불가능\n";
      }

      else if ((source == 2 && destination == 4) ||(source == 4 && destination == 2)) 
      {
         cout << "\t \t \t항공 정보" << endl << endl;
         cout << "항공사:\t출발시각:\t도착시각:\t가격:\t\t분류:\n";
         cout << "1.아시아나(1)\t08:00\t\t11:05\t\t50,000\t\t환불가능\n";
         cout << "2.대한항공(2)\t14:00\t\t17:05\t\t45,000\t\t환불가능\n";
         cout << "3.제주에어(3)\t19:00\t\t22:05\t\t56,000\t\t환불가능\n";
      }
      else if ((source == 3 && destination == 4) ||(source == 4 && destination == 3)) {
         cout << "\t \t \t항공 정보" << endl << endl;
         cout << "항공사:\t출발시각:\t도착시각:\t가격:\t\t분류:\n";
         cout << "1.아시아나(1)\t08:00\t\t11:05\t\t58,000\t\t환불가능\n";
         cout << "2.대한항공(2)\t14:00\t\t17:05\t\t55,080\t\t환불가능\n";
         cout << "3.제주에어(3)\t19:00\t\t22:05\t\t60,500\t\t환불가능\n";
      }
      else if (source == destination) {
         cout << "\n출발지와 목적지가 동일할 수 없습니다. 다시 입력해주세요. \n";
         return input_the_journey();
      }
      else {
         cout << "\n잘못된 입력입니다. 다시 입력해주세요. \n" ;
         return input_the_journey();
      }
   }

   int   input_flight() // 항공편 선택하는 함수 선언 및 정의
   {
      cout << "\n선택을 입력 해주세요. " ;
      cin >> choice;
      switch (choice) 
      {
      case 1: 
         cout << "\n\t선택된 항공 정보 " << endl;
         cout << "아시아나" << endl;
         strcpy(fly_destination, "아시아나"); // 문자열에 복사
         cout << "출발시각 : 08:00" << endl;
         cout << "도착시각 : 11:05" << endl;
         strcpy(to_journey_time, "8:00");         
         strcpy(to_journey_destination, "11:05"); 
         break;
      case 2: 
         cout << "\n\t선택된 항공 정보 "<<endl;
         cout << "대한항공" << endl;
         strcpy(fly_destination, "대한항공"); 
         cout << "출발시각 : 14:00" << endl;
         cout << "도착시각 : 17:05" << endl;
         strcpy(to_journey_time, "14:00");        
         strcpy(to_journey_destination, "17:05"); 
         break;
      case 3: 
         cout << "\n\t선택된 항공 정보 " << endl;
         cout << "제주에어" << endl;
         strcpy(fly_destination, "제주에어"); 
         cout << "출발시각 : 19:00" << endl;
         cout << "도착시각 : 22:05" << endl;
         strcpy(to_journey_time, "19:00");        
         strcpy(to_journey_destination, "22:05"); 
         break;
      default:
         cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
         return input_flight();
      }
   }
};

class international_Reserve // 국제선 예약 함수 선언 및 정의 (안유성)
{
protected:
   int flight_numberingi;
   char f_i[10], to_journey_destinationi[7], to_journey_timei[7];
   long int date_of_journeyi;
   int sourcei, destinationi, choicei;

public: 
   void i_flight_numbering() {
      global++;
      flight_numberingi = global;
   }
   
   int input_the_journeyi() 
                      
   {
      cout << "이동할 날짜를 입력해주세요 (DDMMYY)." << " 올바른 값을 입력해주세요. " ;
      cin >> date_of_journeyi;
      cout << "1.런던(1) \t2.하와이(2) \t3.블라디보스톡(3) \t4.시드니(4) \t5.뉴욕(5) "<< endl << endl;
      cout << "출발지를 입력해주세요. ";
      cin >> sourcei;
      cout << "목적지를 입력해주세요. ";
      cin >> destinationi;
      cout << "\t \t \t항공 정보" << endl << endl;

      if ((sourcei == 1 && destinationi == 3) ||
         (sourcei == 3 && destinationi == 1)) 
      {
         cout << "항공사:\t출발시각:\t도착시각:\t가격:\t\t분류:\n";
         cout << "1.대한항공(1)\t10:00\t\t14:05\t\t25,000\t환불가능\n";
         cout << "2.영국항공(2)\t14:00\t\t18:05\t\t21,500\t환불가능\n";
         cout << "3.하와이안항공(3)\t18:00\t\t22:05\t\t24,000\t환불가능\n";
      }

      else if ((sourcei == 1 && destinationi == 4) ||
         (sourcei == 4 && destinationi == 1)) 
      {
         cout << "항공사:\t출발시각:\t도착시각:\t가격:\t\t분류:\n";
         cout << "1.대한항공(1)\t10:00\t\t14:05\t\t25,500\t환불가능\n";
         cout << "2.영국항공(2)\t14:00\t\t18:05\t\t21,300\t환불가능\n";
         cout << "3.하와이안항공(3)\t18:00\t\t22:05\t\t24,650\t\t환불가능\n";
      }

      else if ((sourcei == 1 && destinationi == 5) ||
         (sourcei == 5 || destinationi == 1)) 
      {
         cout << "항공사:\t출발시각:\t도착시각:\t가격:\t\t분류:\n";
         cout << "1.대한항공(1)\t10:00\t\t14:05\t\t62,500\t환불가능\n";
         cout << "2.영국항공(2)\t14:00\t\t18:05\t\t57,420\t환불가능\n";
         cout << "3.하와이안항공(3)\t18:00\t\t22:05\t\t64,800\t환불가능\n";
      }

      else if ((sourcei == 2 && destinationi == 3) ||
         (sourcei == 3 && destinationi == 2)) 
      {
         cout << "항공사:\t출발시각:\t도착시각:\t가격:\t\t분류:\n";
         cout << "1.대한항공(1)\t10:00\t\t14:05\t\t18,800\t환불가능\n";
         cout << "2.영국항공(2)\t14:00\t\t18:05\t\t19,900\t환불가능\n";
         cout << "3.하와이안항공(3)\t18:00\t\t22:05\t\t19,700\t환불가능\n";
      }

      else if ((sourcei == 2 && destinationi == 4) ||
         (sourcei == 4 && destinationi == 2)) 
      {
         cout << "항공사:\t출발시각:\t도착시각:\t가격:\t\t분류:\n";
         cout << "1.대한항공(1)\t10:00\t\t14:05\t\t35,000\t환불가능\n";
         cout << "2.영국항공(2)\t14:00\t\t18:05\t\t48,500\t환불가능\n";
         cout << "3.하와이안항공(3)\t18:00\t\t22:05\t\t52,250\t환불가능\n";
      }

      else if (sourcei == 2 && destinationi == 5 ||
         (sourcei == 5 && destinationi == 2))
      {
         cout << "항공사:\t출발시각:\t도착시각:\t가격:\t\t분류:\n";
         cout << "1.대한항공(1)\t10:00\t\t14:05\t\t92,500\t환불가능\n";
         cout << "2.영국항공(2)\t14:00\t\t18:05\t\t88,550\t환불가능\n";
         cout << "3.하와이안항공(3)\t18:00\t\t22:05\t\t86,500\t환불가능\n";

      }
      else if (sourcei == destinationi) 
      {
         cout << "잘못된 입력입니다. 다시 입력해주세요.\n\n" << endl;
         return input_the_journeyi();
      }
      else
      {
         cout << "잘못된 입력입니다. 다시 입력해주세요.\n\n\n";
         return input_the_journeyi();
      }
   }

   int
      input_flighti() 
   {
      cout << "\n선택을 입력 해주세요. " ;
      cin >> choicei;
      switch (choicei) 
      {
      case 1:
         cout << "\n\t선택된 항공 정보  ";
         cout << "대한항공" << endl;
         strcpy(f_i, "대한항공"); 
         cout << "출발시각 : 10:00" << endl;
         cout << "도착시각 : 14:05" << endl;
         strcpy(to_journey_timei, "10:00");        
         strcpy(to_journey_destinationi, "14:05"); 
         break;
      case 2: 
         cout << "\n\t선택된 항공 정보 : ";
         cout << "영국항공" << endl;
         strcpy(f_i, "영국항공"); 
         cout << "출발시각 : 14:00" << endl;
         cout << "도착시각 : 18:05" << endl;
         strcpy(to_journey_timei, "14:00");      
         strcpy(to_journey_destinationi, "18:05"); 
      case 3:
         cout << "\n\t선택된 항공 정보 : ";
         cout << "하와이안항공" << endl;
         strcpy(f_i, "하와이안항공");
         cout << "출발시각  : 18:00" << endl;
         cout << "도착시각 : 22:05" << endl;
         strcpy(to_journey_timei, "18:00");        
         strcpy(to_journey_destinationi, "22:05"); 
         break;
      default: 
         cout << "잘못된 입력입니다." << endl;
         return input_flighti();
      }
   }
};

class passenger // (김보현)
   : public domestic_Reserve,
   public international_Reserve
{
protected: 
   char passenger_name[20], last_name[20], passenger_email[50];
   int passenger_age, passenger_gender;
   long int contact_numbers;

public: 
   long int getContact() { return contact_numbers; }
   void p_detail(int x) 
   {
      if (x == 1)
      {
         input_the_journey(); 
         input_flight();     
      }
      else {
         input_the_journeyi(); 
         input_flighti();      
      }
      cout << "\n\n\n세부 정보를 기재해주세요.";
      cout << "\nFirst Name : ";
      cin >> passenger_name;
      cout << "Last Name : ";
      cin >> last_name;
   }
   int passenger_gender_check(){
      cout << "\n성별 : 남자(1) 여자(2) ";
      cin >> passenger_gender;
      if (passenger_gender > 2) 
      {
         cout << "\n\n잘못된 입력입니다. 다시 입력해주세요.\n" << endl;
         return passenger_gender_check(); 
      }
   }
   void more_details() 
   {
      cout << "나이 : ";
      cin >> passenger_age;
      cout << "이메일 : ";
      cin >> passenger_email;
      cout << "전화 번호 : ";
      cin >> contact_numbers;
      cout << "\n\n\t입력 정보\n";
      cout << "이름 : " << passenger_name << " " << last_name << endl;
      cout << "성별 : " << passenger_gender << endl;
      cout << "나이 : " << passenger_age << endl;
      cout << "이메일 : " << passenger_email << endl;
      cout << "전화번호 : " << contact_numbers << endl;
   }

   int getflight_numbering() 
   {
      return flight_numbering;
   }

   int getflight_numberingi() 
   {
      return flight_numberingi;
   }

   void display_Reservation() 
   {
      cout << "항공사 : " << fly_destination << endl;
      cout << "항공편 번호 : " << flight_numbering << endl;   
      cout << "이름 : " << passenger_name << " " << last_name << endl;
      cout << "출발날짜 : " << date_of_journey << endl;
      cout << "출발시각 : " << to_journey_time << endl;
      cout << "도착시각 : " << to_journey_destination;
   }

   void display_Reservationi() 
   {
      cout << "항공사 : " << f_i << endl;
      cout << "항공편 번호 : " << flight_numberingi << endl;
      cout << "이름 : " << passenger_name << " " << last_name << endl;
      cout << "출발날짜 : " << date_of_journeyi << endl;
      cout << "출발시각 : " << to_journey_timei << endl;
      cout << "도착시각 : " << to_journey_destinationi;
   }
};

class payment //결제 (박솔지)
{
protected:
   long int sel, bank_sel, card_no, thru, cvc, dep_name;
   char passwd[10];
   char cellular[15];
   
public:
   void pay_method() 
   {
      cout << "\n\n\n사용 가능한 결제 방식\n";
      cout << "\n1.카드 결제(1) \n2.무통장 입금(2) \n3.카카오 페이(3)";

      cout << "\n\n원하시는 결제 방식(번호) : ";
      cin >> sel;
      switch (sel) {
      case 1: // 카드 결제
         cout << "\n카드 번호 : ";
         cin >> card_no;
         cout << "\n만기일 : ";
         cin >> thru;
         cout << "\nCVC 숫자 : ";
         cin >> cvc;
         cout << "\n비밀번호 : ";
         cin >> passwd;
         cout << "\n결제가 완료되었습니다.\n";
         break;
      case 2: // 무통장 입금
         cout << "가능한 은행 : \n1.국민은행(1) \n2.신한은행(2) \n3.기업은행(3) \n4.하나은행(4) \n5.우리은행(5)";
         cout << "\n원하시는 은행을 선택해주세요 : ";
         cin >> bank_sel;
         cout << "\n선택하신 은행 : " << bank_sel;
         cout << "\n예금주명을 입력해주세요 : ";
         cin >> dep_name;
         cout << "\n3일 이내에 입금이 완료되지 않을 시 예약이 취소됩니다.\n";
         cout << "해당 은행의 입금 계좌번호 : ";
         switch (bank_sel) {
         case 1:
            cout << "국민 은행 : 123-456-789" << endl;
            break;
         case 2:
            cout << "신한 은행 : 1423-1456-789" << endl;
            break;
         case 3:
            cout << "기업 은행 : 823-46-78119" << endl;
            break;
         case 4:
            cout << "하나 은행 : 9123-4526-789-01" << endl;
            break;
         case 5:
            cout << "우리 은행 : 1253-612-1958" << endl;
            break;
         default:
            break;
         }
         break;
      case 3: //카카오 페이

         cout << "\n휴대폰 번호를 입력해주세요. ";
         cin >> cellular;
         cout << "\n카카오페이 비밀번호를 입력해주세요. ";
         cin >> passwd;
         cout << "\n결제가 완료되었습니다.\n";
         break;
      default:
         cout << "\n유효하지 않은 번호입니다.\n\n";
         return pay_method();
      }
   }
};

void makefile(passenger psg)//국내선 파일 생성 (김보현)
{
   long int contact_number = psg.getContact();

   char cur_path[1024];
   getcwd(cur_path, 1024);

   string filepath = (cur_path);
   filepath += "/" + to_string(contact_number);

   //디렉토리 생성.
   mkdir(filepath.c_str(), 0755);

   //이동 후 파일 생성
   if (chdir(filepath.c_str()) == -1) {
      perror("chdir()error");
   }

   ofstream fdin("domestic.txt", ios::binary | ios::app);

   fdin.write((char*)&psg, sizeof(psg)); // 파일에 쓰기
   fdin.close();                          // 파일 닫으삼

   //다시 원래자리로 이동
   chdir("..");
}

void cancellation_ticket(int ccl) // 예매한 티켓 취소 (박솔지)
{
   passenger psg;
   int fd = 0;
   ifstream fdout("domestic.txt", ios::binary | ios::app); //파일 읽기
   ofstream fdin("domestic1.txt",
      ios::binary | ios::app); // 새로운 파일에 쓰기
   fdout.read((char*)&psg, sizeof(psg)); // 파일 읽기
   while (fdout) {
      if (psg.getflight_numbering() != ccl)      //항공편 번호 확인
         fdin.write((char*)&psg, sizeof(psg)); // 파일에 쓰기
      else {
         psg.display_Reservation(); // 세부내용 출력하기
         cout << "\n귀하의 티켓은 취소되었습니다.\n"
            << "환불 금액 : 50,000원\n";
         fd++; //항공편 번호 찾았으면 증가
      }
      fdout.read((char*)&psg,
         sizeof(psg)); // 파일 내에서 다른 기록 읽기
   }
   if (fd == 0) // f==0이면 항공편 번호 못 찾은거
      cout << "해당 티켓을 찾을 수 없습니다.\n";
   fdout.close();                          
   fdin.close();                           
   remove("domestic.txt");                  //예전파일 지우기
   rename("domestic1.txt", "domestic.txt"); //이름 바꾸기
}

void checking_ticket(int ct) // 항공편 번호나 티켓 정보 확인하기 (정기현)
{
   passenger psg;
   int fd = 0;
   ifstream fdout("domestic.txt", ios::binary); // 파일 열기
   fdout.read((char*)&psg, sizeof(psg));       // 파일 읽기
   while (fdout) {
      if (psg.getflight_numbering() == ct) // 항공편 번호 확인
      {
         psg.display_Reservation(); // 세부내용 출력
         cout << "\n귀하의 티켓" << endl;
         fd++; //못 찾았으면 fd 증가
         break;
      }
      fdout.read((char*)&psg,
         sizeof(psg)); // 동일 파일 내에서 다른 기록 읽기
   }
   fdout.close(); 
   if (fd == 0)   // fd==0이면 해당 번호 못 찾은거
      cout << "해당 티켓을 찾을 수 없습니다." << endl;
}
void makefilei(passenger psg) // 국제선 예약 파일 열기 (김보현)
{
   long int contact_number = psg.getContact();

   char cur_path[1024];
   getcwd(cur_path, 1024);

   string filepath = (cur_path);
   filepath += "/" + to_string(contact_number);

   //디렉토리 생성.
   mkdir(filepath.c_str(), 0755);

   //이동 후 파일 생성
   if (chdir(filepath.c_str()) == -1) {
      perror("chdir()error");
   }

   ofstream fdin("international.txt", ios::binary | ios::app);
   fdin.write((char*)&psg, sizeof(psg)); // 파일에 쓰기
   fdin.close();                        

   //원래 자리로 이동
   chdir("..");
}

void cancellation_ticketi(int cti) // 티켓 취소 함수 (박솔지)
{
   passenger psg;
   int fd = 0;
   ifstream fdout("international.txt", ios::binary | ios::app); //파일 열기
   ofstream fdin("international1.txt",
      ios::binary | ios::app); // 새 파일에 쓰기
   fdout.read((char*)&psg, sizeof(psg)); // 이전 파일 읽기
   while (fdout) {
      if (psg.getflight_numberingi() != cti)     // 항공편 번호 확인하기
         fdin.write((char*)&psg, sizeof(psg)); // 새로운 파일에 작성하기
      else {
         psg.display_Reservationi();
         cout << "귀하의 티켓은 삭제되었습니다.\n"
            << "환불 금액 : 10,000원\n";
         fd++; // 항공편 번호 못 찾으면 fd 증가
      }
      fdout.read((char*)&psg,
         sizeof(psg)); 
   }
   if (fd == 0) //  fd==0이면 항공편 번호 못 찾은거
      cout << "\n해당 티켓을 찾을 수 없습니다.\n";
   fdout.close();                                    
   fdin.close();                                    
   remove("international.txt");                       // 이전 파일 삭제
   rename("international1.txt", "international.txt"); 
}
void checking_ticketi(int cti) //(정기현)
{
   passenger psg;
   int fd = 0;
   ifstream fdout("international.txt", ios::binary); 
   fdout.read((char*)&psg, sizeof(psg));           
   while (fdout) {
      if (psg.getflight_numberingi() == cti) //항공편 번호 확인
      {
         psg.display_Reservationi(); 
         cout << "\n귀하의 티켓" << endl;
         fd++; //항공편 번호 못 찾으면 fd 증가
         break;
      }
      fdout.read((char*)&psg,
         sizeof(psg));
   }
   fdout.close();
   if (fd == 0)   //  f==0이면 항공편 번호 못 찾은거
      cout << "해당 티켓을 찾을 수 없습니다." << endl;
}

int main() // (정기현 총괄)
{
   class domestic_Reserve d1;     
   class international_Reserve i1; 
   class passenger p1;            
   class payment p2;               
   int ch, ch1, n;               
   char input;                    
   do                              
   {
      system("clear");
      cout << "\n\n \t\t항공편 예약을 도와드리겠습니다!" << endl << endl;
      cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>\n";
      cout << "\t   합리적인 가격으로 귀하의 티켓을 예매하세요!" << endl;
      cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>";

      cout << "\n\n\t\t\t1. 항공편 예약하기(1) \n\t\t\t2. 예매 취소하기(2) "
         "\n\t\t\t3. 예매내역 확인하기(3) \n\t\t\t4. 나가기(4)"<< endl;
      cout << "\n\t\t  선택을 입력 해주세요 : ";
      cin >> ch;
      switch (ch) 
      {
      case 1:
         system("clear");
         cout << "\n\n1. 국내선(1) \t2. 국제선(2)"<< endl;
         cout << "\n옵션을 입력해주세요. " ;
         cin >> ch1;
         switch (ch1) 
         {
         case 1: 
            p1.d_flight_numbering();
            p1.p_detail(1); 
            p1.passenger_gender_check();
            p1.more_details();
            p2.pay_method();
            p1.display_Reservation();
            makefile(p1); 
            break;
         case 2:            
            p1.p_detail(2); 
            p1.i_flight_numbering();
            p1.passenger_gender_check();
            p1.more_details();
            p2.pay_method();
            p1.display_Reservationi();
            makefile(p1);
            break;
         default:
            cout << "잘못된 입력입니다. 다시 입력해주세요.\n" << endl;
            return main();
         }
         break;
      case 2:
         
         system("clear");
         cout << "\n1. 국내선(1) \t2. 국제선(2)" << endl;
         cout << "\n옵션을 입력해주세요. " ;
         cin >> ch1;
         if (ch1 == 1) {
            cout << "귀하의 항공편 번호를 입력해주세요. ";
            cin >> n;
            cancellation_ticket(n);
         }
         else if (ch1 == 2) {
            cout << " 귀하의 항공편 번호를 입력해주세요. ";
            cin >> n;
            cancellation_ticket(n); 
         }
         else {
            cout << "잘못된 입력입니다. 다시 입력해주세요.\n\n";
            return main();
         }
         break;
      case 3:
         system("clear");
         cout << "\n1. 국내선(1) \t2. 국제선(2)"<< endl;
         cout << "\n옵션을 입력해주세요. ";
         cin >> ch1;
         if (ch1 == 1) {
            cout << "귀하의 항공편 번호를 입력해주세요. ";
            cin >> n;
            cancellation_ticket(n);
         } 
         else if (ch1 == 2) {
            cout << "귀하의 항공편 번호를 입력해주세요. ";
            cin >> n;
            cancellation_ticket(n); 
         }
         else {
            cout << "잘못된 입력입니다. 다시 입력해주세요.\n\n";
            return main();
         }
         break;
      case 4:
         system("clear");
         cout << "\n\n\t\t\t\tBrought to you by code-projects.org";
         return 0;
      default:
         cout << "잘못된 입력입니다. 다시 입력해주세요..\n\n\n\n" << endl;
         return main();
      }
      cout << "\n\n\nContinue? (y/Y)" << endl;
      cin >> input;
   } while (input == 'Y' || input == 'y');
   return 0;
}
