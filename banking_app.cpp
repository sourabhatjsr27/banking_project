#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

bool isValidName(string s){
       
       int len = s.length();

       for(int i=0; i < len ; i++){
             
             if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
                    continue;
             else 
                 return false;
       }

       return true;

}

bool isPanValid(string s){
       int i = 0;

       if(s.length() != 10)
          return false;
       else{
             while(i < 5){
                 
                 if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)){
                         i++;
                          continue;
                 }else{
                    return false;
                 }
                 
             }

             while(i < 9){
                  
                  if(s[i] >= 48  && s[i] <= 57){
                      i++;
                      continue;
                  }else
                      return false;
             }
             
             if((s[9] >= 65 && s[9] <= 90) || (s[9] >= 97 && s[9] <= 122))
                return true;
             else 
                return false;
            
             
       }
}



bool isAdharValid(string s){
      
      if(s.length() != 12)
         return false;
      
      for(int i = 0;i < 12 ; i++){

           if(s[i] >= 48  && s[i] <= 57){
                      continue;
           }else
                      return false;
      }

      return true;
}

class Bank{
     string ifsc_code;

     public:
        string acc_holder_name;
        int acc_no;
        string pan_card_no;
        string adhar_card_no;

        string return_ifsc_code(){
             ifsc_code = "UTIB000037";
             return ifsc_code;
         }
};

class Savings_Account:public Bank{
     
     public:
     
     long int balance;

         Savings_Account(){
            balance = 0;
         }
         
         void accept(){
                 
            cout << "Enter account number : " << endl;
            cin >> acc_no;

            while(1){
                 string s;

                 cout << "Enter account holder name : " << endl;
                 cin >> s;

                 if(isValidName(s)){
                    acc_holder_name = s;
                    break;
                 }

                 cout << "Invalid name (should contain only alphabets)" << endl;

            }
            
            while(1){
                 string s;
                 cout << "Enter pancard no : " << endl;
                 cin >> s;

                 if(isPanValid(s)){
                    pan_card_no = s;
                    break;
                 }

                 cout << "Invalid pan card no" << endl;
            }
           
            while(1){
                string s;
                cout << "Enter addhar card no : " << endl;
                cin >> s;

                if(isAdharValid(s))
                {
                    adhar_card_no = s;
                    break;
                }

                cout << "Invalid adhar no " << endl;
            }
            
            
             int d;
             cout << "Enter the amount for intial account balance " << endl;
             cin >> d;
             deposit(d);

             cout << endl;
         }
         

         void deposit(int x){   
               cout << "Account balance before deposit : " << balance << endl ;
               balance += x; 
               cout << "You have deposited " << x << " rupees " << endl;
               cout << "You're current account balance is : " << balance << endl;    
         }
         
         bool withdrawl(int x){
               
               if(balance - x < 0){
                    cout << "insufficient amount " << endl;
                    return false;
               }else{
                    cout << "You have withdrew amount " << x << " from bank account : " << endl;
                    balance = balance - x;
                    cout << "Availabel balance is : " << balance << endl;
                    return true;
               }
         }
         
         void show_balance(){
             cout << " The current balance is : " << balance << endl;
         }

         void show_details(){
            cout << " Account holder name : " << acc_holder_name << endl;
            cout << " Account no : " << acc_no << endl;
            cout << " Ifsc Code : " << return_ifsc_code() << endl;
            cout << " Pancard : " << pan_card_no << endl;
            cout << " Adhar Card : " << adhar_card_no << endl;
            cout << " Balance : " << balance << endl;
         }
};

class Current_Account:public Bank{
     
     public:

    
     long int balance;

         Current_Account(){
            balance = 0;
         }

         void accept(){

            cout << "Enter account number : " << endl;
            cin >> acc_no;

            while(1){
                 string s;

                 cout << "Enter account holder name : " << endl;
                 cin >> s;

                 if(isValidName(s)){
                    acc_holder_name = s;
                    break;
                 }

                 cout << "Invalid name (should contain only alphabets)" << endl;

            }
            
            while(1){
                 string s;
                 cout << "Enter pancard no : " << endl;
                 cin >> s;

                 if(isPanValid(s)){
                    pan_card_no = s;
                    break;
                 }

                 cout << "Invalid pan card no" << endl;
            }
           
            while(1){
                string s;
                cout << "Enter addhar card no : " << endl;
                cin >> s;

                if(isAdharValid(s))
                {
                    adhar_card_no = s;
                    break;
                }

                cout << "Invalid adhar no " << endl;
            }
            
            
            int d;
            cout << "Enter the amount for intial account balance " << endl;
            cin >> d;
            deposit(d);

         }
         

         void deposit(int x){   
               cout << "Account balance before deposit : " << balance << endl ;
               balance += x; 
               cout << " You have deposited " << x << " rupees " << endl;
               cout << " You're current account balance is : " << balance << endl;    
         }
         
         bool withdrawl(int x){
               
               if(balance - x < 0){
                    cout << "insufficient amount " << endl;
                    return false;
               }else{
                    cout << "You have withdrew amount " << x << " from bank account : " << endl;
                    balance = balance - x;
                    cout << "Availabel balance is : " << balance << endl;
                    return true;
               }
         }
         
         void show_balance(){
             cout << " The current balance is : " << balance << endl;
         }

         void show_details(){
            cout << " Account holder name : " << acc_holder_name << endl;
            cout << " Account no : " << acc_no << endl;
            cout << " Pancard : " << pan_card_no << endl;
            cout << " Adhar Card : " << adhar_card_no << endl;
            cout << " Balance : " << balance << endl;
         }
};



int main(){

    Savings_Account sa[5];
    Current_Account ca[5];

    Bank b;

    int i = 0;
    int j = 0;

    while(1){

        int choice,acc,acc2;
        int flag = 0;
        int d;
        int amt;
        int a1=-1;
        int a2=-1;
        char c1;
        char c2;
        cout << "Enter 1 for creating saving account : " << endl;
        cout << "Enter 2 for creating current account : " << endl;
        cout << "Enter 3 for depositing money in account : " << endl;
        cout << "Enter 4 for withdraw money from account :  " << endl;
        cout << "Enter 5 for transaction between two accounts : " << endl;
        cout << "Enter 6 for account details : " << endl;
        cout << "Enter 9 for exit " << endl;
        cin  >> choice;

        switch(choice){
             case 1 : sa[i].accept();
                      i++;
                      break;
             case 2 : ca[i].accept();
                      j++;
                      break;

             case 3 : cout << "Enter the account no  " << endl;
                      cin >> acc;

                      cout << "Enter the amount you want to deposit : " << endl;
                      cin >> d;  

                      for(int k = 0; k < 5 ; k++)
                         {
                            if(sa[k].acc_no == acc){
                               sa[k].deposit(d);
                               flag =1;
                            }else if (ca[k].acc_no == acc){
                               ca[k].deposit(d); 
                               flag = 1;
                            }else
                                 continue;     
                         }

                         if(flag == 0)
                            cout << "Enter Account no is incorrect " << endl;


                      break;

             case 4 : cout << "Enter account number from which you want to withdraw amount : " << endl;
                      cin >> acc;

                      cout << "Enter amount : " << endl;
                      cin >> amt;

                      
                            for(int k=0; k<5 ; k++){
                                if(sa[k].acc_no == acc){
                                    sa[k].withdrawl(amt);
                                    flag = 1;
                                }else if(ca[k].acc_no == acc){
                                    ca[k].withdrawl(amt);
                                    flag = 1;
                                }else
                                    continue;
                            }

                       if(flag == 0)
                          cout << "Incorrect Account number " << endl;
                      
                     break;

             case 5 : cout << "Enter account no from which amount is going to be withdrawn : " << endl;
                      cin >> acc;

                      cout << "Enter account no from which amount is going to be deposited : " << endl;
                      cin >> acc2;

                      cout << "Enter the amount you want to transfer : " << endl;
                      cin >> amt;

                      
                       
                       //searcing account 1 
                       for(int k=0; k<5 ; k++){
                                if(sa[k].acc_no == acc){
                                    if(sa[k].balance < amt){
                                        cout << "Not sufficient balance is available in account 1 " << endl;
                                        break;
                                    }
                                    a1 = k;
                                    c1 = 's';
                                }else if(ca[k].acc_no == acc){
                                    a1 = k;
                                    c1 = 'c';
                                }else
                                    continue;
                            }
                        if(a1 == -1){
                            cout << "Entered account no 1 doesnt exist " << endl;
                            break;
                        }
                        
                        //searching account 2
                        for(int k=0; k<5 ; k++){
                                if(sa[k].acc_no == acc2){
                                    a2 = k;
                                    c2 = 's';
                                }else if(ca[k].acc_no == acc2){
                                    a2 = k;
                                    c2 = 'c';
                                }else
                                    continue;
                            }
                        if(a2 == -1){
                            cout << "Entered account no 2 is doesn't exist " << endl;
                            break;
                        }

                        

                        if(c1 == 's' && c2 == 's'){
                            sa[a1].withdrawl(amt);
                            sa[a2].deposit(amt);
                        }else if(c1 == 's' && c2 == 'c'){
                            sa[a1].withdrawl(amt);
                            ca[a2].deposit(amt);
                        }else if(c1 == 'c' && c2 == 's'){
                            ca[a1].withdrawl(amt);
                            sa[a2].deposit(amt);
                        }else{
                            ca[a1].withdrawl(amt);
                            ca[a2].deposit(amt);
                        }

                        break;
             case 6 :
                      cout << "Enter account number: " << endl;
                      cin >> acc;

                      for(int k=0;k<5;k++){
                         
                           if(sa[k].acc_no == acc){
                               sa[k].show_details();
                               flag=1;
                               break;
                               
                           }else if(ca[k].acc_no == acc){
                               ca[k].show_details();
                               flag=1;
                               break;
                           }else
                               continue;
                      }
                      
                      if(flag == 0)
                      cout << "Invalid account number : " << endl;

                      break;
             case 9 : 
                      exit(0);
                      break;
             default: 
                      cout << " Enter correct choice " << endl;
            

        }
          
    }

    return 0;
}

