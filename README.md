# tema-pa-ab-2025



## Getting started

To make it easy for you to get started with GitLab, here's a list of recommended next steps.

Already a pro? Just edit this README.md and make it your own. Want to make it easy? [Use the template at the bottom](#editing-this-readme)!

## Add your files

- [ ] [Create](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#create-a-file) or [upload](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#upload-a-file) files
- [ ] [Add files using the command line](https://docs.gitlab.com/topics/git/add_files/#add-files-to-a-git-repository) or push an existing Git repository with the following command:

```
cd existing_repo
git remote add origin https://gitlab.com/bogdangheorghe98/tema-pa-ab-2025.git
git branch -M main
git push -uf origin main
```

## Integrate with your tools

- [ ] [Set up project integrations](https://gitlab.com/bogdangheorghe98/tema-pa-ab-2025/-/settings/integrations)

## Collaborate with your team

- [ ] [Invite team members and collaborators](https://docs.gitlab.com/ee/user/project/members/)
- [ ] [Create a new merge request](https://docs.gitlab.com/ee/user/project/merge_requests/creating_merge_requests.html)
- [ ] [Automatically close issues from merge requests](https://docs.gitlab.com/ee/user/project/issues/managing_issues.html#closing-issues-automatically)
- [ ] [Enable merge request approvals](https://docs.gitlab.com/ee/user/project/merge_requests/approvals/)
- [ ] [Set auto-merge](https://docs.gitlab.com/user/project/merge_requests/auto_merge/)

## Test and Deploy

Use the built-in continuous integration in GitLab.

- [ ] [Get started with GitLab CI/CD](https://docs.gitlab.com/ee/ci/quick_start/)
- [ ] [Analyze your code for known vulnerabilities with Static Application Security Testing (SAST)](https://docs.gitlab.com/ee/user/application_security/sast/)
- [ ] [Deploy to Kubernetes, Amazon EC2, or Amazon ECS using Auto Deploy](https://docs.gitlab.com/ee/topics/autodevops/requirements.html)
- [ ] [Use pull-based deployments for improved Kubernetes management](https://docs.gitlab.com/ee/user/clusters/agent/)
- [ ] [Set up protected environments](https://docs.gitlab.com/ee/ci/environments/protected_environments.html)

***

# Editing this README

When you're ready to make this README your own, just edit this file and use the handy template below (or feel free to structure it however you want - this is just a starting point!). Thanks to [makeareadme.com](https://www.makeareadme.com/) for this template.

## Suggestions for a good README

Every project is different, so consider which of these sections apply to yours. The sections used in the template are suggestions for most open source projects. Also keep in mind that while a README can be too long and detailed, too long is better than too short. If you think your README is too long, consider utilizing another form of documentation rather than cutting out information.

## Name
Choose a self-explaining name for your project.

## Description
Let people know what your project can do specifically. Provide context and add a link to any reference visitors might be unfamiliar with. A list of Features or a Background subsection can also be added here. If there are alternatives to your project, this is a good place to list differentiating factors.

## Badges
On some READMEs, you may see small images that convey metadata, such as whether or not all the tests are passing for the project. You can use Shields to add some to your README. Many services also have instructions for adding a badge.

## Visuals
Depending on what you are making, it can be a good idea to include screenshots or even a video (you'll frequently see GIFs rather than actual videos). Tools like ttygif can help, but check out Asciinema for a more sophisticated method.

## Installation
Within a particular ecosystem, there may be a common way of installing things, such as using Yarn, NuGet, or Homebrew. However, consider the possibility that whoever is reading your README is a novice and would like more guidance. Listing specific steps helps remove ambiguity and gets people to using your project as quickly as possible. If it only runs in a specific context like a particular programming language version or operating system or has dependencies that have to be installed manually, also add a Requirements subsection.

## Usage
Use examples liberally, and show the expected output if you can. It's helpful to have inline the smallest example of usage that you can demonstrate, while providing links to more sophisticated examples if they are too long to reasonably include in the README.

## Support
Tell people where they can go to for help. It can be any combination of an issue tracker, a chat room, an email address, etc.

## Roadmap
If you have ideas for releases in the future, it is a good idea to list them in the README.

## Contributing
State if you are open to contributions and what your requirements are for accepting them.

For people who want to make changes to your project, it's helpful to have some documentation on how to get started. Perhaps there is a script that they should run or some environment variables that they need to set. Make these steps explicit. These instructions could also be useful to your future self.

You can also document commands to lint the code or run tests. These steps help to ensure high code quality and reduce the likelihood that the changes inadvertently break something. Having instructions for running tests is especially helpful if it requires external setup, such as starting a Selenium server for testing in a browser.

## Authors and acknowledgment
Show your appreciation to those who have contributed to the project.

## License
For open source projects, say how it is licensed.

## Project status
If you have run out of energy or time for your project, put a note at the top of the README saying that development has slowed down or stopped completely. Someone may choose to fork your project or volunteer to step in as a maintainer or owner, allowing your project to keep going. You can also make an explicit request for maintainers.



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
