# Royal Hunt


    Am creat cate o biblioteca pentru fiecare pas plus o biblioteca care contine functiile pentru coada, una pentru arbore si una pentru graf. In biblioteca pentru graf se afla si rezolvarea pentru pasul 7 (acesta nu are biblioteca separata).

    Pas1:
    -creez coada in main si apelez functia citeste
    -in functia citeste, citesc datele din fisier linie cu linie, ignorand prima linie si le formatez astfel incat sa respecte regulile din cerinta:
    1. Elimin caracterul newline de la sfârșitul liniei.
    2. Verific prezența unui spațiu și a caracterului `;`, altfel ignoră linia.
    3. Extrag: statutul social (ca șir de caractere), numele complet al participantului, experiența (float), varsta(int).
    4. Aplic transformările necesare asupra statutului și numelui: functia modificstatutsocial returneaza enumul corespunzator statutului social gasit, iar functia modificanume face prima litera mare si restul mici si adauga "-" intre numele participantului. Experienta si varsta sunt citite direct din linie cu sscanf
    5. Creez structura participant și o inserează în coadă folosind enqueue.
    -functia enqueue creeaza un nod care contine informatiile participantului si il adauga la sfarsitul cozii, daca coada e goala nodul devine atat primul cat si ultimul element. Are complexitate O(1).
    -liniile ce nu respecta formatul se ignora
    -participantii sunt afisati in fisier cu functia scrie 
    
    Pas2:
    -pentru pasul 2 se apeleaza functia organizarecandidati care are rolul de a organiza participanții într-un arbore binar de căutare BST în funcție de statutul lor social (LORD sau CAVALERI,AVENTURIERI)
    -in functie ambii bst: bst_lorzi si bst_cavaleri_aventurieri sunt initializati cu NULL
    -cat timp coada nu e nula, se extrage cate un participant din coada cu functia dequeue, iar daca acesta are statutul de lord e inserat cu functia insert in bst_lorzi, altfel in bst_cavaleri_aventurieri 
    -functia dequeue scoate un participant din coadă, returnând elementul scos și actualizeaza structura cozii. Are complexitate temporala si spatiala O(1).
    -functia insert inserează un nod într-un arbore binar de căutare si returneaza adresa nodului investigat. Are complexitate O(log N), N-nr de noduri, daca arborele e echilibrat.
    -arborele este scris in fisier cu functia scriebst
    -complexitatea temporala a functiei organizarecandidati e O(M*log N) daca avem M participanti in coada, iar cea spatiala este O(M).

    Pas 3:
    -pentru pasul 3 este apelata in main functia citestecontestatii. Aceasta citeste datele din fisier linie cu linie apoi le modifica conform cerintei. Aplica transformările necesare asupra statutului și numelui, experientei si varstei ca la pasul 1.
    -sterg participantul pentru care s-a facut contestatie din arbore cu functia deletenode
    -in deletenode se compară experiența nodului curent cu experiența participantului ce trebuie șters: dacă experiența participantului este mai mică decât a nodului curent, se caută în subarborele stâng, altfel se caută în subarborele drept. 
    Dacă găsim un nod cu experiența și numele corespunzătoare, se analizează ce tip de nod este: dacă nodul nu are copii, se elimină nodul și se inlocuieste cu copilul său, dacă nodul are un singur copil, este înlocuit cu acel copil, dacă nodul are doi copii, se caută cel mai mic nod din subarborele drept, se înlocuiește conținutul nodului curent cu acesta, și se șterge nodul minim găsit recursiv. Complexitatea te cfmporara este O(log N), N-nr de noduri, daca arborele e echilibrat(cel mai bun caz), altfel O(N). Cea spatiala este O(h), h-inaltimea arborelui.

   Pas4:
   -fac o structura traseu care contine numele traseului, un vector pentru paduri si numarul padurilor
   -in main creez heap-ul cu functia createheap de complexitate temporala O(1), iar spatiala O(N).
   -apelez functia asignaretrasee in care:
     -cu functia citestetraseu  sunt citite din fișier informațiile despre trasee (nume și paduri asociate) și salvate într-un tablou de structuri traseu. Aceasta returneaza nr de trasee.
     -sunt parcurse traseele și, alternativ, pentru traseele cu index par, se extrage un participant din arborele bstlorzi, iar pentru index impar, se extrage un participant din arborele bstca cu functia scoatemaxim de complexitate O(h).
     -Pentru fiecare participant sunt retinute in variabila c numele, experiența și traseul asociat.
     -datele participantului sunt adaugate in heap cu functia insertheap care inserează un element într-un heap și menține proprietatea de heap folosind heapify_up. Complexitatea temporala a insert si heapify_up e O(logN), iar cea spatiala O(1).
  
    Pas5:
    -Funcția actualizareexperienta actualizează experiența fiecărui participant din heap. Pentru fiecare participant, verifică dacă traseul său se regăsește în lista de trasee si îi adaugă experiența dobândită. După actualizare, se reconstruiește heap-ul folosind heapify_down pentru a păstra ordinea în funcție de experiență. La final, informațiile sunt scrise în fișierul de ieșire.
    -functia heapify_down: compară nodul cu copiii săi stânga și dreapta și, dacă unul dintre copii are o experiență mai mare, interschimbă nodul curent cu cel mai mare copil. Complexitatea temporala si spatiala e O(log N)

    Pas6:
    -Funcția printHeap identifica primii 3 participanți cu cea mai mare experiență din heap. Parcurge toți participanții din heap și îi inserează într-un vector auxiliar aux[3], păstrând mereu doar cei mai buni 3 în ordine descrescătoare. La sfarsit îi scrie în fișier.
    -complexitatea temporala este O(N),N-nr de candidati si cea spatiala este O(1).

    Pas7:
    -este creat graful in main cu functia creategraf.
    -Cand citesc datele din fisier contorizez gradul de iesire si de intrare pentru fiecare nod in vectorii gradiesire, gradintrare
    -apelez functia nrtraseegenerate care cauta toate traseele posibile de la nodurile cu grad de intrare 0 la cele cu grad de iesire 0, folosind parcurgerea DFS. Fiecare cale validă este salvată într-o matrice, apoi toate traseele sunt sortate și afișate într-un fișier.
    -functia DFS parcurge in adancime graful construind toate traseele valide. Complexitatea temporala este O(V+E), iar cea spatiala e O(V)
    -matricea e sortata cu functia sorteaza care compara elementele a 2 linii, retine pozitia la care valorile nu mai sunt egale. Daca nu sunt ordonate interschimba liniile element cu element. Complexitatea temporala e O(n^2), adica O(nrtrase^2) in cazul meu, iar cea spatiala e O(1)
    -complexitatea temporala totala este O(E+V+n^2), iar spatiala O(V+n^2)

    La final, in main eliberez memoria pentru heap, arbore, graf si coada cu functiile freegraf, deleteheap, freebst, freecoada. (Am scurgeri de memorie, dar nu am reusit sa le rezolv in timp util)

    Am adaugat comentarii si in cod unde explic mai detaliat ce se intampla.# Royal-Hunt
