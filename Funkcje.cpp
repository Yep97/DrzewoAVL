#include<stddef.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include"Funkcje.hh"




/****************************************************************************
                                 ROTACJE
 ****************************************************************************
 */

/*
 * Funkcja rotacji PP - "Pojedyncza w prawo"
 *
 * Wejscie:
 * korzen - korzen drzewa
 * A      - wezel, w ktorym wystepuje zaburzenie rownowagi w prawym poddrzewie
 *
 * Wyjscie:
 * Wykonanie rotacji PP
 *
 */

DrzewoAVL * AVL::RotacjaPP(DrzewoAVL * A)  {

   DrzewoAVL * B = A -> prawo;                                 // W B umieszczamy prawe dziecko A
   DrzewoAVL * R = A -> r;                                     // W r umieszczamy rodzica A

   A -> prawo = B -> lewo;                                      // Prawym dzieckiem A staje sie lewe dziecko B

   if(A -> prawo) {
      A -> prawo -> r = A;                                      // Jesli dziecko istnieje to jego rodziciem jest teraz A
   }

   B -> lewo = A;                                               // Wezel A staje sie lewym dzieckiem wezla B
   B -> r = R;                                                  // Rodzic A staje sie rodzicem B
   A -> r = B;                                                  // Rodzicem A staje sie wezel B

   if (R)   {                                                   // Czy wezel A byl korzeniem

      if(R -> lewo == A)  {                                     // Jesli nie uaktualnij rodzica
         R -> lewo = B;
      }
      else {
         R -> prawo = B;
      }
   }
   else {
      korzen = B;                                               // Jesli tak uaktualnij korzen
   }

   if(B -> wr == -1)   {                                       // Modyfikacja wspolczynnika rownowagi
      A -> wr = B -> wr = 0;
   }
   else  {
      A -> wr = -1;
      B -> wr = 1;
   }

   return B;
}

/*
 * Funkcja rotacji LL - "Pojedyncza w lewo"
 *
 * Wejscie:
 * korzen - korzen drzewa
 * A      - wezel, w ktorym wystepuje zaburzenie rownowagi w lewym poddrzewie
 *
 * Wyjscie:
 * Wykonanie rotacji LL
 *
 */

DrzewoAVL * AVL::RotacjaLL(DrzewoAVL * A)  {

   DrzewoAVL * B = A -> lewo;                                  // W B umieszczamy lewe dziecko A
   DrzewoAVL * R = A -> r;                                     // W r umieszczamy rodzica A

   A -> lewo = B -> prawo;                                      // Lewym dzieckiem A staje sie lewe dziecko B

   if(A -> lewo) {                                              // Jesli dziecko istnieje to jego rodziciem jest teraz A
      A -> lewo -> r = A;
   }

   B -> prawo = A;                                              // Wezel A staje sie prawym dzieckiem wezla B
   B -> r = R;                                                  // Rodzic A staje sie rodzicem B
   A -> r = B;                                                  // Rodzicem A staje sie wezel B

   if(R) {                                                      // Czy wezel A byl korzeniem
      if (R -> lewo == A)  {                                    // Jesli nie uaktualnij rodzica
         R -> lewo = B;
      }
      else  {
         R -> prawo = B;
      }
   }
   else  {
      korzen = B;                                              // Jesli tak uaktualnij korzenm
   }

   if (B -> wr == 1)   {                                       // Modyfikacja wspolczynnika rownowagi
      A -> wr = B -> wr = 0;
   }
   else  {
      A -> wr = 1;
      B -> wr = -1;
   }

   return B;
}

/*
 * Funkcja rotacji PL - "Podwojna w prawo-lewo"
 *
 * Wejscie:
 * korzen - korzen drzewa
 * A      - wezel, w ktorym wystepuje zaburzenie rownowag w prawym poddrzewie
 *
 * Wyjscie:
 * Wykonanie rotacji PL
 *
 */

DrzewoAVL * AVL::RotacjaPL(DrzewoAVL * A)  {

   DrzewoAVL * B = A -> prawo;                              // B - prawe dziecko wezla A
   DrzewoAVL * C = B -> lewo;                               // C - lewe dziecko wezla B
   DrzewoAVL * R = A -> r;                                  // R - rodzic wezla A

   B -> lewo = C -> prawo;                                  // Prawy potomek wezla C staje sie lewym potomkiem wezla B

   if(B -> lewo)  {                                         // Jesli lewy potomek B istnieje to B staje sie jego rodzicem
      B -> lewo -> r = B;
   }

   A -> prawo = C -> lewo;                                  // Lewy potomek C staje sie prawym potomkiem wezla A

   if(A -> prawo) {                                         // Jesli prawy potomek A istnieje to A staje sie jego rodzicem
      A -> prawo -> r = A;
   }

   C -> lewo = A;                                           // Lewym potomkiem C staje sie wezel A
   A -> r = C;                                              // Rodzicem A staje sie wezel C
   C -> prawo = B;                                          // Prawym potomkiem C staje sie wezel B
   B -> r = C;                                              // Rodzicem B staje sie wezel C
   C -> r = R;                                              // Rodzicem C staje sie rodzic A

   if(R) {                                                  // Sprawdzamy czy C jest korzeniem
      if(R -> lewo == A)   {                                // Nie, zmieniamy dziecko rodzica A na C
         R -> lewo = C;
      }
      else  {
         R -> prawo = C;
      }
   }
   else  {
      korzen = C;                                           // Tak, ustaw nowy korzen
   }

   if(C -> wr == -1)  {                                     // Uaktualniamy wspolczynniki rownowagi
      A -> wr = 1;
   }
   else   {
      A -> wr = 0;
   }

   if(C -> wr == 1)   {
      B -> wr = -1;
   }
   else   {
      B -> wr = 0;
   }

   C -> wr = 0;

   return C;
}

/*
 * Funkcja rotacji LP - "Podwojna w lewo-prawo"
 *
 * Wejscie:
 * korzen - korzen drzewa
 * A      - wezel, w ktorym wystepuje zaburzenie rownowag w lewym poddrzewie
 *
 * Wyjscie:
 * Wykonanie rotacji LP
 *
 */

DrzewoAVL * AVL::RotacjaLP(DrzewoAVL * A)  {

   DrzewoAVL * B = A -> lewo;                               // B - Lewe dziecko wezla A
   DrzewoAVL * C = B -> prawo;                              // C - Prawe dziecko wezla B
   DrzewoAVL * R = A -> r;                                  // R - Rodzic wezla A

   B -> prawo = C -> lewo;                                  // Lewy potomek L staje sie prawym potomkiem wezla B

   if(B -> prawo)  {                                        // Jesli prawy potomek B istnieje
      B -> prawo -> r = B;                                  // To B staje sie jego rodzicem
   }

   A -> lewo = C -> prawo;                                  // Prawe dziecko C staje sie lewym dzieckiem A

   if(A ->lewo)   {                                         // Jesli lewe dziecko A istnieje
      A -> lewo -> r = A;                                   // To A staje sie jego rodzicem
   }

   C -> prawo = A;                                          // Prawym dzieckiem C staje sie A
   C -> lewo = B;                                           // Lewym dzieckiem C staje sie B
   A -> r = C;                                              // Rodzicem A staje sie C
   B -> r = C;                                              // Rodzicem B staje sie C
   C -> r = R;                                              // Rodzicem C staje sie rodzic A

   if(R)    {                                               // Sprawdzamy czy C jest korzeniem
      if(R -> lewo == A)   {                                // Nie, zmieniamy dziecko z rodzica A na C
         R -> lewo = C;
      }
      else  {
         R -> prawo = C;
      }
   }
   else   {
      korzen = C;                                           // Tak, ustaw nowy korzen
   }

      if(C -> wr == 1)  {                                   // Ustawiamy nowe wspolczynniki rownowagi
         A -> wr = -1;
      }
      else  {
         A -> wr = 0;
      }

      if(C -> wr == -1)    {
         B -> wr = 1;
      }
      else  {
         B -> wr = 0;
      }

      C -> wr = 0;

      return C;
}


/****************************************************************************
                                 FUNKCJE
 ****************************************************************************
 */




/*
 * Funckja Dodaj - Wstawianie nowego wezla do drzewa
 *
 * Wejscie:
 * korzen - korzen drzewa AVL
 * n      - nowy wezel
 *
 * Wyjscie:
 * true  - dodanie wezla do drzewa
 * false - wezel nie zostal dodany i jest usuniety z pamieci
 *
 * Dane pomocnicze:
 * w -> klucz   - klucz wezla w
 * w -> lewo  - lewy potomek wezla w
 * w -> prawo - prawy potomek wezla w
 * w -> p     - rodzic wezla w
 * w -> wr    - wspolczynnik rownowagi wezla
 *
 */

bool AVL::Dodaj(DrzewoAVL * n)  {

   DrzewoAVL * X = korzen;                                        // X - Wezel drzewa, ktory jest korzeniem
   DrzewoAVL * Y;                                                 // Y - Wezel drzewa
   DrzewoAVL * Z;                                                 // Z - Wezel drzewa

   Y = n -> lewo = NULL;                                          // Zerowanie pola lewo wstawionego elementu
   Y = n -> prawo = NULL;                                         // Zerowanie pola prawo wstawionego elementu
   n -> wr = 0;                                                   // Zerowanie wspolczynnika rownowagi wstawionego elementu

   while(X) {                                                     // Przeszukiwanie drzewo

      if(X -> klucz == n -> klucz)  {                             // Jesli natrafisz na wezel o tym samym kluczu, co klucz wstawionego elementu
         delete n;                                                // Usun wezel
         return false;
      }

      Y = X;                                                      // Zapamietaj adres odwiedzanego elementu

      if(n -> klucz < X -> klucz)   {                             // Jesli klucz wstawionego elementu jest mniejszy od klucza biezacego elementu
         X = X -> lewo;                                           // To wybierz lewego potomka jako nastepny do odzwiedzonego elementu
      }
      else  {
         X = X -> prawo;                                          // Inaczej wybierz prawego potomka
      }
   }

   ilosc++;

   if(!(n -> r = Y))  {                                           // Jesli drzewo jest puste
      korzen = n;                                                 // To wstaw pierwszy element
      return true;
   }

   if(n -> klucz < Y -> klucz)   {                                // Jesli klucz n jest mniejszy od klucza y
      Y -> lewo = n;                                              // To przypisz n do pola lewo jego rodzica
   }
   else   {
      Y -> prawo = n;                                             // To przypisz n do pola prawo jego rodzica
   }

   if(Y -> wr)   {                                                // Jesli wspolczynnik rownowagi rodzica Y jest rozny od 0
      Y -> wr = 0;                                                // To go wyzeruj
      return true;
   }

   if(Y -> lewo == n)   {                                         // Sprawdzamy wysokosc poddrzewa
      Y -> wr = 1;                                                // Jesli lewa jest "ciezsza" to ustaw 1
   }
   else   {
      Y -> wr = -1;                                               // Jesli jest na prawej galezi to ustaw -1
   }

   Z = Y -> r;                                                    // Przemieszczamy sie w gore drzewa szukacjac wezla, ktory stracil rownowage

   while(Z)   {

      if(Z -> wr)   {                                             // Obie galezie byly w rownowadze
         break;
      }

      if(Z -> lewo == Y)   {                                      // W zaleznosci w ktorej galezi wezla znajduje sie potomek Y (Dana galaz jest ciezsza)
         Z -> wr = 1;                                             // Jesli lewa jest ciezsza to ustaw 1
      }
      else   {
         Z -> wr = -1;                                            // Jesli prawa to ustaw -1
      }

      Y = Z;
      Z = Z -> r;                                                 // Przemieszczamy sie w gore drzewa
   }

   if(!Z)   {
       return true;
   }

   if(Z -> wr == 1)   {                                           // Lewa galaz Z byla ciezsza

      if(Z -> prawo == Y)   {                                     // Prawa galaz ze wstawionym elementem rownowazy lewa
         Z -> wr = 0;
	      return true;
      }

      if(Y -> wr == -1)   {                                       // Jesli przewazalo lewe poddrzewo wezla Z i jest to poddrzewo, w ktorym wstawilismy nowy element
         RotacjaLP(Z);                                            // Jesli prawe poddrzewo wezla Y jest ciezsze to wykonaj rotacje LP
      }
      else   {
         RotacjaLL(Z);                                            // Jesli lewe poddrzewo wezla Y jest ciezsze to wykonaj rotacje LL
      }

      return true;
   }
   else   {

      if(Z -> lewo == Y)   {                                      // Lewa galaz ze wstawionym elementem rownowazy prawa
         Z -> wr = 0;
	      return true;
      }

      if(Y -> wr == 1)   {                                        // Jesli przewazalo prawe poddrzewo wezla Z i jest to poddrzewo, w ktorym wstawilismy nowy element
         RotacjaPL(Z);                                            // Jesli prawe poddrzewo wezla Y jest ciezsze to wykonaj rotacje PL
      }
      else   {
         RotacjaPP(Z);                                            // Jesli lewe poddrzewo wezla Y jest ciezsze to wykonaj rotacje PP
      }
      return true;
   }
}

/*
 * Funckja Usun - Usuwanie wezla z drzewa
 *
 * Wejscie:
 * korzen - korzen drzewa AVL
 * X      - Wezel do usuniecia
 *
 * Wyjscie:
 * Wykonanie operacji usuniecia wezla z drzewa AVL
 *
 */

DrzewoAVL * AVL::Usun(DrzewoAVL * X)   {
   DrzewoAVL * T;                                                 // Wezel drzewa
   DrzewoAVL * Y;                                                 // Wezel drzewa
   DrzewoAVL * Z;                                                 // Wezel drzewa
   bool gniazdo;                                                  // Zmienna logiczna, ktora wskazuje zagniezdzenie

   if((X -> lewo) && (X -> prawo))   {                            // Jesli wezel posiada dwoch potomokow to
      Y = Usun(Poprzedni(X));                                     // Usun poprzedni wezel X i przypisz do niego Y
      ilosc++;
      gniazdo = false;                                            // Ustaw gniazdo na false
   }
   else   {                                                       // Jesli nie posiada dwoch potomkow
      if(X -> lewo)   {                                           // Jesli wezel posiada jednego potomka lub nie posiada zadnego
         Y = X -> lewo;                                           // Przypisz lewego potomka X wezlowi Y
         X -> lewo = NULL;
      }
      else   {
         Y = X -> prawo;                                          // Przypisz prawego potomka X wezlowi Y
         X -> prawo = NULL;
      }
      X -> wr = 0;                                                // Zerujemy, gdyz jesli X mial potomka to trail do Y
      gniazdo = true;                                             // Ustaw gniazdo na true
   }

   if(Y)   {                                                      // Jesli Y istnieje to
      Y -> r = X -> r;                                            // Ustaw rodzica X jako rodzica Y

      Y -> lewo = X -> lewo;                                      // Ustaw lewe dziecko X jako lewe dziecko Y
      if(Y -> lewo)  {                                            // Jesli lewe dziecko Y istnieje
         Y -> lewo -> r = Y;                                      // To przypisz mu rodzcia Y
      }

      Y -> prawo = X -> prawo;                                    // Ustaw prawe dziecko X jako prawe dziecko Y
      if(Y -> prawo) {                                            // Jesli prawe dziecko Y istnieje
         Y -> prawo -> r = Y;                                     // To przypisz mu rodzica Y
      }
     Y -> wr = X -> wr;
   }

   if(X -> r)   {                                                  // Jesli rodzic X istnieje to
      if(X -> r -> lewo == X)    {                                 // Jesli jest to prawy rodzic
         X -> r -> lewo = Y;                                       // To jego potomkiem staje sie Y
      }
      else   {                                                     // Jesli jest to lewy rodzic
         X -> r -> prawo = Y;                                      // To jego potomkiem staje sie Y
      }
   }
   else   {                                                        // Jesli rodzic X nie istnieje
      Y = korzen;                                                  // Wstaw Y do korzenia
   }

   if(gniazdo)   {                                                 // Jesli gniazdo istnieje to
      Z = Y;                                                       // Przypisujemy wskazniki, zaczynamy poruszac sie w kierunku korzenia drzewa
      Y = X -> r;

      while(Y)   {
         if(Y -> wr != 0)    {                                     // Zaczynamy sprawdzac przypadki!
            if(Y -> lewo == Z)   {                                 // *Przypadek NR 1* // Jesli lewym dzieckiem Y jest Z to
               Y -> wr = -1;                                       // Ustaw wspolczynnik rownowagi na -1 i przerwij petle
               break;
            }
            else   {                                               // Jesli nie to
               Y -> wr = 1;                                        // Ustaw wspolczynnik rownowagi na 1 i przerwij petle
               break;
            }
         }
         else    {                                                 // Jesli wspolczynnik rownowagi jest rowny 0
            if(((Y -> wr == 1 ) || (Y -> lewo == Z)) && ((Y -> wr == -1) || (Y -> prawo == Z)))    {           // *Przypadek NR 2*
               Y -> wr = 0;
               Z = Y;                                              // Przechodzimy na wyzszy poziom drzewa
               Y = Y -> r;
            }
            else   {
               if(Y -> lewo == Z)   {                              // Jesli lewym dzieckiem Y jest Z to
                  T = Y -> prawo;                                  // T wskazuje prawego potomka Y
               }
               else  {                                             // Jesli nie jest to
                  T = Y -> lewo;                                   // T wskazuje lewego potomka Y
               }

               if(T -> wr ==  0)  {                                // *Przypadek NR 3*
                  if(Y -> wr == 1)  {                              // *Przypadek NR 3A* // Jesli wspolczynnik rownowagi jest rowny 1 to
                     RotacjaLL(Y);                                 // Wykonaj rotacje lewo - lewo
                  }
                  else  {                                          // Jesli nie to
                     RotacjaPP(Y);                                 // Wykonaj rotacje prawo - prawo
                  }
                  break;
               }
               else if(Y -> wr != T -> wr)   {                     // *Przypadek NR 3B*
                  if(Y -> wr == 1)  {                              // Jesli wspolczynnik rownowagi jest rowny 1 to
                     RotacjaLL(Y);                                 // Wykonaj rotacje lewo - lewo
                  }
                  else  {                                          // Jesli nie
                     RotacjaPP(Y);                                 // Wykonaj rotacje prawo - prawo
                  }

                  Z = T;                                           // Idziemy na wyzszy poziom drzewa
                  Y = T -> r;
               }
               else  {                                             // *Przypadek NR 3C*
                  if(Y -> wr == 1)  {                              // Jesli wspolczynnik rownowagi jest rowny 1 to
                      RotacjaLP(Y);                                // Wykonaj rotacje lewo - prawo
                  }
                  else  {                                          // Jesli nie
                     RotacjaPL(Y);                                 // Wykonaj rotacje prawo - lewo
                  }
                  Z = Y -> r;
                  Y = Z -> r;
               }
            }                                                      // else od if(((Y -> wr == 1 ) || (Y -> lewo == Z)) && ((Y -> wr == -1) || (Y -> prawo == Z)))
         }                                                         // else od if(Y -> wr != 0)
      }                                                            // while(Y)
   }                                                               // if(gniazdo)
   ilosc--;
   return X;
}
/*
 * Funkcja wypisz korzen - wypisuje korzen drzewa
 */
DrzewoAVL * AVL::WypiszKorzen(DrzewoAVL * X)   {
   if(korzen)  {
      std::cout << " " << korzen -> klucz << std::endl;
   }
   else {
      std::cout << " Brak korzenia" << std::endl;
   }
   return korzen;
}
/*
 * Funkcja wyswietl wysokosc - zwraca wartoœæ wysokoœci
 */
int AVL::WyswietlWysokosc(DrzewoAVL * &korzen) {
   if(korzen == NULL) {
      return 0;
   }
   else  {
      int Lwys = WyswietlWysokosc(korzen -> lewo);
      int Pwys = WyswietlWysokosc(korzen -> prawo);
   if(Lwys > Pwys)  return(Lwys + 1);                                // Sprawdz lew¹ stronê i zworc max wartosc
   else             return(Pwys + 1);                                // Sprawdz praw¹ stronê i zwroc max wartosc
   }
}
/*
 * Funkcja max wysokosc - wyswietla zwrocona wartosc funkcji wyswietl wysokosc
 */
int AVL::MaxWys(DrzewoAVL * X)  {
   std::cout << " " << AVL::WyswietlWysokosc(korzen) << std::endl << std::endl;
   return 0;
}

/****************************************************************************
                           RESZTA FUNKCJI
 ****************************************************************************
 */


DrzewoAVL * AVL::Maksimum(DrzewoAVL *X) {                         // Zwraca wezel z maksymalnym kluczem
   while(X -> prawo)   {
      X = X -> prawo;
   }
      return X;
}

DrzewoAVL * AVL::Poprzedni(DrzewoAVL * X)  {                      // Zwraca wezel poprzednika
   if(X -> lewo)   {
      return Maksimum (X -> lewo);
   }

   DrzewoAVL * Y;

   do   {
      Y = X;
      X = X -> r;
   }
   while(X && (X -> prawo != Y));

   return X;
}

void AVL::WypiszWezly()   {                                         // Funkcja wypisuje wezly drzewa AVL
   std::cout << " Liczba wezlow drzewa AVL: " << ilosc << std::endl << std:: endl;
}

DrzewoAVL * AVL::Szukaj(int klucz)  {                               // Funkcja wyszukuje wezel drzewa i zwraca jego wartosc
   DrzewoAVL * X = korzen;

   while((X) && (X -> klucz != klucz))  {
      if(klucz < X -> klucz)  {
         X = X -> lewo;
      }
      else  {
         X = X -> prawo;
      }

   }
   return X;
}

/*
 * Funkcja wyswietlania drzewa AVL
 */
DrzewoAVL * AVL::WyswietlDrzewo(DrzewoAVL * &X, int poziom) {       // Zmienna poziom odpowiada za poziom galezi
   int i;
   if(X)  {                                                         // Jesli drzewo istnieje to je wyswietl
      WyswietlDrzewo(X -> prawo, poziom + 1);
      std::cout << std::endl;
      if(X == korzen) std::cout << "Korzen -> ";
      for(i = 0; i < poziom && X != korzen; i++)   {
         std::cout << "           ";
      }
      std::cout << X -> klucz;
      WyswietlDrzewo(X -> lewo, poziom + 1);
   }
   std::cout << std::endl;
   return korzen;
}

void AVL::Preorder(DrzewoAVL * X)   {                               // Funkcja przejscia preorder
   if(X)    {
      std::cout << " " << X -> klucz << std::endl;
      Preorder(X -> lewo);
      Preorder(X -> prawo);
   }
}

void AVL::Postorder(DrzewoAVL * X)  {                               // Funkcja przejscia postorder
   if(X)    {
      Postorder(X -> lewo);
      Postorder(X -> prawo);
      std::cout << " " << X -> klucz << std::endl;
   }
}

void AVL::Inorder(DrzewoAVL * X)    {                               // Funkcja przejscia inorder
   if(X)    {
      Inorder(X -> lewo);
      std::cout << " " << X -> klucz << std::endl;
      Inorder(X -> prawo);
   }
}
