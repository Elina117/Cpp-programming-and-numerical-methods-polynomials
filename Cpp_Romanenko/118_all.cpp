#include <iostream>
#include <cmath>
#include <vector>

//118(а)

int main() {
  

   double sum = 0.0;
   bool wow = true;  

   for (int i = 1; i <= 10000; ++i) {
       if (wow) {
           sum += 1.0 / i;
       }
       else {
           sum -= 1.0 / i;
       }

       wow = !wow;
   }

   std::cout << "Результат: " << sum << std::endl;

   return 0;
}

//118(б)
 
int main() {
  

   double sum1 = 0.0;
   double sum2 = 0.0;
   double sum = 0.0; 

   for (int i = 1; i <= 9999; i = i + 2) 
   {
       sum1 += 1.0 / i;
   }

   for (int i = 2; i <= 10000; i=i+2) 
   {
       
       sum2 += 1.0 / i;
       
   }

   sum = sum1 - sum2;

   std::cout << "Результат: " << sum << std::endl;

   return 0;
}

//118(в)

int main() {
   

   double sum = 0.0;
   bool wow = true;  

   for (int i = 10000; i >= 1; i--) {
       if (wow) {
           sum -= 1.0 / i;
       }
       else {
           sum += 1.0 / i;
       }

       wow = !wow;
   }

   std::cout << "Результат: " << sum << std::endl;

   return 0;
}

//118(г)

int main() {
   

   double sum1 = 0.0;
   double sum2 = 0.0;
   double sum = 0.0; 

   for (int i = 9999; i >=1;i=i-2 )
   {
       sum1 += 1.0 / i;
   }

   for (int i = 10000; i >=2; i=i-2) {
       
       sum2 -= 1.0 / i;
       
   }

   sum = sum1 + sum2;

   std::cout << "Результат: " << sum << std::endl;

   return 0;
}