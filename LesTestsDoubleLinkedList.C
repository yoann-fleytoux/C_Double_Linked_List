#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "DoubleLinkedList.h"

/*------------------------------------------------------------------------------
|  Tests Double Linked List                                        |
------------------------------------------------------------------------------*/
// tests constructeur
bool testConstructeurDoubleLinkedListIsEmpty()
{
     DoubleLinkedList l;
     return (l.empty());
}

bool testConstructeurDoubleLinkedListSizeAZero()
{
     DoubleLinkedList l;
     return (l.size()== 0);
}

bool testExceptionConstructeurDoubleLinkedListback()
{
     DoubleLinkedList l;
     try
     {
        l.back();
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

bool testExceptionConstructeurDoubleLinkedListfront()
{
     DoubleLinkedList l;
     try
     {
        l.front();
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

bool testExceptionConstructeurDoubleLinkedListpop()
{
     DoubleLinkedList l;
     try
     {
        l.pop();
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

// test constructeur par recopie
bool testConstructeurRecopie()
{
     DoubleLinkedList l1;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l1.push(it);
     it.key = string ("adouble");
     it.definition = string("En passant par la ligne jaune.");
     l1.push(it);
     it.key = string ("aster");
     it.definition = string("Composee ornementale aux capitules formes de fleurons jaunes entoures de ligules violettes ou blanches (200 especes).");
     l1.push(it);
     DoubleLinkedList l2(l1);
     
     if(l1.size() != l2.size()) return false;
     
     while(!l1.empty() && !l2.empty())
     {
        if(!(l1.front() == l2.front())) return false;
        l1.pop();
        l2.pop();
     }
     
     return true;
}

// test operateur affectation
bool testOperateurAffectation()
{
     DoubleLinkedList l1;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l1.push(it);
     it.key = string ("adouble");
     it.definition = string("En passant par la ligne jaune.");
     l1.push(it);
     it.key = string ("aster");
     it.definition = string("Composee ornementale aux capitules formes de fleurons jaunes entoures de ligules violettes ou blanches (200 especes).");
     l1.push(it);
     DoubleLinkedList l2;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l2.push(it);
     
     l2 = l1;
     
     if(l1.size() != l2.size()) return false;
     
     while(!l1.empty() && !l2.empty())
     {
        if(!(l1.front() == l2.front())) return false;
        l1.pop();
        l2.pop();
     }
     
     return true;
}

// tests après insertion un élément
bool testInsertionPremierElementIsNotEmpty()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     return (!l.empty());
}

bool testInsertionPremierElementSizeEgalUn()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     return (l.size() == 1);
}

bool testInsertionPremierElementIsfront()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     Item dernier;
     dernier.key = string ("adoucissant");
     dernier.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     return (l.front() == dernier);
}

bool testInsertionPremierElementIsBack()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     Item premier;
     premier.key = string ("adoucissant");
     premier.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     return (l.back() == premier);
}

// tests après insertion et suppression un élément
bool testInsertionSuppressionPremierElement()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     l.pop();
     return (l.empty());
}

// tests après insertion deux éléments
bool testInsertionDeuxElementsIsNotEmpty()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     it.key = string ("adouble");
     it.definition = string("En passant par la ligne jaune.");
     l.push(it);
     return (!l.empty());
}

bool testInsertionDeuxElementsSizeEgalDeux()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     it.key = string ("adouble");
     it.definition = string("En passant par la ligne jaune.");
     l.push(it);
     return (l.size() == 2);
}

bool testInsertionDeuxElementsIsfront()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     it.key = string ("adouble");
     it.definition = string("En passant par la ligne jaune.");
     l.push(it);
     Item dernier;
     dernier.key = string ("adoucissant");
     dernier.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     return (l.front() == dernier);
}

bool testInsertionDeuxElementsIsBack()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     it.key = string ("adouble");
     it.definition = string("En passant par la ligne jaune.");
     l.push(it);
     Item premier;
     premier.key = string ("adouble");
     premier.definition = string("En passant par la ligne jaune.");
     return (l.back() == premier);
}

// tests après insertion deux éléments et suppression(s)
bool testInsertionDeuxElementsSuppressionUnElementEmptyEtSize()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     it.key = string ("adouble");
     it.definition = string("En passant par la ligne jaune.");
     l.push(it);
     l.pop();
     return (!l.empty() && l.size() == 1);
}

bool testInsertionDeuxElementsSuppressionUnElementFrontEtBack()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     it.key = string ("adouble");
     it.definition = string("En passant par la ligne jaune.");
     l.push(it);
     l.pop();
     Item premier;
     premier.key = string ("adouble");
     premier.definition = string("En passant par la ligne jaune.");
     return (l.front() == premier && l.back() == premier);
}

// tests search
bool testSearchPremier()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     it.key = string ("adouble");
     it.definition = string("En passant par la ligne jaune.");
     l.push(it);
     it.key = string ("aster");
     it.definition = string("Composee ornementale aux capitules formes de fleurons jaunes entoures de ligules violettes ou blanches (200 especes).");
     l.push(it);
     string key("aster");
     return (l.search(key) != NULL && l.search(key)->key == key);
}

bool testSearchSecond()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     it.key = string ("adouble");
     it.definition = string("En passant par la ligne jaune.");
     l.push(it);
     it.key = string ("aster");
     it.definition = string("Composee ornementale aux capitules formes de fleurons jaunes entoures de ligules violettes ou blanches (200 especes).");
     l.push(it);
     string key("adouble");
     return (l.search(key) != NULL && l.search(key)->key == key);
}

bool testSearchTer()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     it.key = string ("adouble");
     it.definition = string("En passant par la ligne jaune.");
     l.push(it);
     it.key = string ("aster");
     it.definition = string("Composee ornementale aux capitules formes de fleurons jaunes entoures de ligules violettes ou blanches (200 especes).");
     l.push(it);
     string key("adoucissant");
     return (l.search(key) != NULL && l.search(key)->key == key);
}

bool testClear()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     it.key = string ("adouble");
     it.definition = string("En passant par la ligne jaune.");
     l.push(it);
     it.key = string ("aster");
     it.definition = string("Composee ornementale aux capitules formes de fleurons jaunes entoures de ligules violettes ou blanches (200 especes).");
     l.push(it);
     l.clear();
     return (l.empty());
}

// tests ensemble items
bool testExceptionPushClefExistante()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     it.key = string ("adouble");
     it.definition = string("En passant par la ligne jaune.");
     l.push(it);
     it.key = string ("aster");
     it.definition = string("Composee ornementale aux capitules formes de fleurons jaunes entoures de ligules violettes ou blanches (200 especes).");
     l.push(it);
     try
     {
        l.push(it);
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

bool testExceptionRemoveClefInexistante()
{
     DoubleLinkedList l;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l.push(it);
     it.key = string ("adouble");
     it.definition = string("En passant par la ligne jaune.");
     l.push(it);
     it.key = string ("aster");
     it.definition = string("Composee ornementale aux capitules formes de fleurons jaunes entoures de ligules violettes ou blanches (200 especes).");
     l.push(it);
     try
     {
        Item it;
        it.key = string ("abasourdir");
        it.definition = string("Provoquer chez quelqu'un un sentiment voisin de la stupeur.");  
        l.remove(it.key);
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

// un test se compose d'un pointeur de fonction et d'un message d'erreur explicite si le test échoue
class TestUnitaire{
   private :  
      // déclaration d'un pointeur de fonction
      // la fonction ne prend pas de paramètres et renvoie un booléen
      typedef bool (*test)();  
      test functionOfTest;
      string errorTest;
   
   public :
      // constructeur de test
      TestUnitaire(test ptrFunction, string message) 
      {
         this->functionOfTest = ptrFunction;
         this->errorTest = message;
      }
      // les accesseurs en lecture
      test getFunctionOfTest() const { return this->functionOfTest; }
      string getErrorTest() const { return this->errorTest; }
};

// initialisation des tests 
void initializeAllTests(vector<TestUnitaire> & lesTests)
{
   lesTests.push_back(TestUnitaire(&testConstructeurDoubleLinkedListIsEmpty, string("test Constructeur par defaut et liste Vide failed")));
   lesTests.push_back(TestUnitaire(&testConstructeurDoubleLinkedListSizeAZero, string("test Constructeur par defaut et taille liste a zero failed")));
   lesTests.push_back(TestUnitaire(&testExceptionConstructeurDoubleLinkedListback, string("test Constructeur par defaut et back leve exception failed")));
   lesTests.push_back(TestUnitaire(&testExceptionConstructeurDoubleLinkedListfront, string("test Constructeur par defaut et front leve exception failed")));
   lesTests.push_back(TestUnitaire(&testExceptionConstructeurDoubleLinkedListpop, string("test Constructeur par defaut et pop leve exception failed")));
   
   lesTests.push_back(TestUnitaire(&testConstructeurRecopie, string("test Constructeur par recopie failed")));
   lesTests.push_back(TestUnitaire(&testOperateurAffectation, string("test Operateur affectation failed")));

   lesTests.push_back(TestUnitaire(&testInsertionPremierElementIsNotEmpty,string("Apres ajout un element la liste est non vide failed"))); 
   lesTests.push_back(TestUnitaire(&testInsertionPremierElementSizeEgalUn,string("Apres ajout un element la liste est de taille 1 failed"))); 
   lesTests.push_back(TestUnitaire(&testInsertionPremierElementIsfront,string("Apres ajout un element dans la liste, le dernier element est cet element failed"))); 
   lesTests.push_back(TestUnitaire(&testInsertionPremierElementIsBack,string("Apres ajout un element dans la liste, le premier element est cet element failed"))); 

   lesTests.push_back(TestUnitaire(&testInsertionSuppressionPremierElement,string("Apres ajout et suppression un element la liste est vide failed"))); 

   lesTests.push_back(TestUnitaire(&testInsertionDeuxElementsIsNotEmpty,string("Apres ajout deux elements la liste est non vide failed"))); 
   lesTests.push_back(TestUnitaire(&testInsertionDeuxElementsSizeEgalDeux,string("Apres ajout deux elements la liste est de taille 2 failed")));
   lesTests.push_back(TestUnitaire(&testInsertionDeuxElementsIsfront,string("Apres ajout deux elements dans la liste, le dernier element est le premier ajoute failed"))); 
   lesTests.push_back(TestUnitaire(&testInsertionDeuxElementsIsBack,string("Apres ajout deux elements dans la liste, le premier element est le dernier ajoute failed"))); 

   lesTests.push_back(TestUnitaire(&testInsertionDeuxElementsSuppressionUnElementEmptyEtSize,string("Apres ajout deux elements dans la liste et une suppression, !empty ou size egal 1 failed")));
   lesTests.push_back(TestUnitaire(&testInsertionDeuxElementsSuppressionUnElementFrontEtBack,string("Apres ajout deux elements dans la liste et une suppression, back ou front failed")));

   lesTests.push_back(TestUnitaire(&testSearchPremier,string("search sur premier element failed")));
   lesTests.push_back(TestUnitaire(&testSearchSecond,string("search sur second element failed")));
   lesTests.push_back(TestUnitaire(&testSearchTer,string("search sur troisieme element failed")));
   
   lesTests.push_back(TestUnitaire(&testClear,string("clear failed")));

   lesTests.push_back(TestUnitaire(&testExceptionPushClefExistante,string("Levee Exception clef existante failed")));
   lesTests.push_back(TestUnitaire(&testExceptionRemoveClefInexistante,string("Levee Exception clef inexistante failed")));
}

// Compte le nombre de tests exécutés
int nombreTestsExecutes(vector<bool> &resultats)
{
    return resultats.size();
}

// Compte le nombre de tests réussis
int nombreTestsReussis(vector<bool> &resultats)
{
    int reussis = 0;
    for (int i = 0; i < resultats.size(); i++) {
        if(resultats[i]) reussis++;
    }
    return reussis;
}

// Compte le nombre de tests échoués
int nombreTestsEchoues(vector<bool> &resultats)
{
    int echoues = 0;
    for (int i = 0; i < resultats.size(); i++) {
        if(!resultats[i]) echoues++;
    }
    return echoues;
}

// test si tous les tests sont ok
bool testsAllOkay(vector<bool> &resultats)
{
     int i;
     for (i = 0; i < resultats.size() && resultats[i]; i++) {}
     return (i == resultats.size());
}

// execution des tests
void runAllTests()
{
     vector<TestUnitaire> lesTests;
     initializeAllTests(lesTests);                          
     vector<bool> resultats(lesTests.size(),false);  
     
     // Exécution automatique des tests          
     for (int i = 0; i < resultats.size(); i++)
     {
         resultats[i]= (*lesTests[i].getFunctionOfTest())();
     }
     
     // Affichage des résultats
     if (testsAllOkay(resultats))
     {
        cout << nombreTestsExecutes(resultats) << " tests executes :" << endl;
        cout << "Tous les tests sont Okay" << endl;
     }
     else 
     {
        cout << "*** ATTENTION ***" << endl;
        cout << "Nombre de tests reussis : " << nombreTestsReussis(resultats) << endl;
        cout << "Nombre de tests echoues : " << nombreTestsEchoues(resultats) << endl;
        for (int i = 0; i < resultats.size(); i++)
        {
            if (!resultats[i])
               cout << lesTests[i].getErrorTest() << endl;
        }
     }
     
     // Tests perso
     /*
     DoubleLinkedList l1;
     Item it;
     it.key = string ("adoucissant");
     it.definition = string("Substance organique utilisee comme appret, ou en fin de lavage, pour rendre les textiles plus agreables au toucher.");
     l1.push(it);
     DoubleLinkedList l2;
     l2 = l1;*/
     
}

int main(int argc, char *argv[])
{
    runAllTests();
    return EXIT_SUCCESS;
}
