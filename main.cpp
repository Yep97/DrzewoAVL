#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<stddef.h>

#include"Funkcje.hh"

// Funkcje wywolujace u¿ywane w switchu
void Dod(AVL * T)  {                                    // Funkcja wywolujaca do funkcji dodaj
   T -> WypiszWezly();
   std::cout << " Podaj ilosc wezlow, ktorych chcesz utworzyc: " << std::endl;
   int i;
   int n;
   DrzewoAVL * X;
   std::cout << " ";
   std::cin >> n;
   std::cout << " Wypisz wezly drzewa" << std::endl;

   for(i = 0; i < n; i++)  {
      X = new DrzewoAVL;
      std::cout << " ";
      std::cin >> X -> klucz;
      T -> Dodaj(X);
   }
   std::cout << std::endl;
   T -> WypiszWezly();
}

void Usn(AVL * T)  {                                    // Funkcja wywolujaca do funkcji usun
   T -> WypiszWezly();

   DrzewoAVL * X;
   int klucz;

   std::cout << " Podaj wezel, ktory chcesz usunac" << std::endl << " ";
   std::cin >> klucz;

   X = T -> Szukaj(klucz);

   if(X) {
      delete T -> Usun(X);
      T -> WypiszWezly();
   }
   else  {
      std::cout << " Brak takiego wezla" << std::endl;
   }
}

void Preorder(AVL * T)  {                               // Funkcja wywolujaca do funkcji preorder
   T -> Preorder(T -> korzen);
}

void Inorder(AVL * T) {                                 // Funkcja wywolujaca do funkcji inorder
   T -> Inorder(T -> korzen);
}

void Postorder(AVL * T) {                               // Funkcja wywolujaca do funkcji postorder
   T -> Postorder(T -> korzen);
}

void WysKorzen(AVL * T) {                               // Funkcja wywolujaca do funckcji wypisujacej korzen
   T -> WypiszKorzen(T -> korzen);
}

void WysDrzewo(AVL * T) {                               // Funkcja wywolujaca do funkcji wyswietlajacej drzewo
   T -> WyswietlDrzewo(T -> korzen,1);
}

void WysWys(AVL * T) {                                  // Funkcja wywolujaca do funkcji wyswietlajacej wyoskosc korzenia
   T -> MaxWys(T -> korzen);
}

int main()  {
   AVL * N  = new AVL();
   char wybor;

   std::cout << " **************************************" << std::endl;
   std::cout << " ** Witaj, w programie drzewa AVL!   **" << std::endl;

   do    {

      std::cout << " **************************************" << std::endl;
      std::cout << " **     Wybierz opcje dla drzewa!    **" << std::endl;
      std::cout << " **************************************" << std::endl;
      std::cout << " ** X - Wyswietl drzewo AVL          **" << std::endl;
      std::cout << " ** D - Operacja dodawania wezla     **" << std::endl;
      std::cout << " ** U - Operacja usuwania  wezla     **" << std::endl;
      std::cout << " ** P - Operacja preorder            **" << std::endl;
      std::cout << " ** I - Operacja inorder             **" << std::endl;
      std::cout << " ** O - Operacja postorder           **" << std::endl;
      std::cout << " ** W - Wyswietl korzen              **" << std::endl;
      std::cout << " ** V - Wyswietl wysokosc            **" << std::endl;
      std::cout << " ** K - Koniec, dzialania prorogramu **" << std::endl;
      std::cout << " **************************************" << std::endl << " ";
      std::cin >> wybor;


      switch(wybor)  {
         case 'X':
            std::cout << " Wyswietl drzewo AVL" << std::endl;
            WysDrzewo(N);
            break;
         case 'D':
            std::cout << " Wykonaj operacje dodania wezla do drzewa AVL" << std::endl;
            Dod(N);
            break;
         case 'U':
            std::cout << " Wykonaj operacje usuniecia wezla z drzewa AVL" << std::endl;
            Usn(N);
            break;
         case 'K':
            std::cout << " Koniec" << std::endl;
            break;
         case 'P':
            std::cout << " Wykonaj operacje preorder" << std::endl;
            Preorder(N);
            break;
         case 'I':
            std::cout << " Wykonaj operacje inorder" << std::endl;
            Inorder(N);
            break;
         case 'O':
            std::cout << " Wykonaj operacje postorder" << std::endl;
            Postorder(N);
            break;
         case 'W':
            std::cout << " Wyswietl korzen" << std::endl;
            WysKorzen(N);
            break;
         case 'V':
            std::cout << " Wyswietl wysokosc drzewa" << std::endl;
            WysWys(N);
            break;
         default:
            std::cout << " Zly wybor funkcji!" << std::endl;
            break;
      }
      if(wybor == 'K')  {
         break;
      }
   }
   while(wybor);
   delete N;
   return 0;
}
