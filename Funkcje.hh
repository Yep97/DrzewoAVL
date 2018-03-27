#ifndef FUNKCJE_HH
#define FUNKCJE_HH
#include<stddef.h>

struct DrzewoAVL  {
   DrzewoAVL *r;		// Rodzic
   DrzewoAVL *lewo;
   DrzewoAVL *prawo;
   int klucz;           // Klucz
   int wr;		   	    // Wspolczynnik rownowagi
};


class AVL   {
   public:

      int ilosc;
      DrzewoAVL * korzen;
      // Deklaracje funkcji progrramu
      DrzewoAVL *  RotacjaPP(DrzewoAVL * A);
      DrzewoAVL *  RotacjaLL(DrzewoAVL * A);
      DrzewoAVL *  RotacjaPL(DrzewoAVL * A);
      DrzewoAVL *  RotacjaLP(DrzewoAVL * A);
      bool         Dodaj(DrzewoAVL * n);
      DrzewoAVL *  Usun(DrzewoAVL * X);
      DrzewoAVL *  Maksimum(DrzewoAVL * X);
      DrzewoAVL *  Poprzedni(DrzewoAVL * X);
      DrzewoAVL *  Szukaj(int klucz);
      DrzewoAVL *  WyswietlDrzewo(DrzewoAVL * &X, int poziom);
      void WypiszWezly();
      void Preorder(DrzewoAVL * X);
      void Inorder(DrzewoAVL * X);
      void Postorder(DrzewoAVL * X);
      DrzewoAVL * WypiszKorzen(DrzewoAVL * X);
      int WyswietlWysokosc(DrzewoAVL * &korzen);
      int MaxWys(DrzewoAVL * X);


      AVL()   {                                                            // Konstruktor klasy AVL
      korzen = NULL;
      ilosc = 0;
      }


      ~AVL()   {                                                           // Destruktor klasy AVL
         while(korzen)   {
         delete(Usun(korzen));
         }
      }


};


#endif
