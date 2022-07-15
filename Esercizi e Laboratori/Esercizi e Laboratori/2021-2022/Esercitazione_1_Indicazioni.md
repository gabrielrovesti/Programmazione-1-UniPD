Questi sono i criteri che verranno utilizzati per valutare le esercitazioni. 

Correttezza (10):

(0-3) il codice non dichiara che problema risolve tramite pre- e post-condizioni, l’implementazione non è terminata, il codice non compila (valido solo se il programma è progettato al calcolatore), le postcondizioni non realizzano la consegna, Il codice compila ma calcola chiaramente qualcosa di completamente diverso da quanto dichiarato nelle post condizioni. Alcune specifiche della consegna non sono state prese in considerazione, semplificando la risoluzione del problema

(5-6) Il codice sembra generalmente corretto. Ad esempio supera gran parte dei test che possono essere pensati senza analizzare bene il problema, ma non sono trattati casi particolari (array vuoti ecc…) che, con particolari input, possono generare la terminazione prematura del programma. Le precondizioni non sono complete

(7-9) Codice funzionante, non riuscirei a pensare a test che facciano fallire il programma. Alcuni comandi/operatori sono usati in modo scorretto anche se non generano un errore (accesso oltre i limiti di un array) oppure non si deallocano dallo heap le strutture non necessarie (per la seconda parte del corso) 

(10) Per tutte le funzioni per cui non sia ovvio, si discute in modo efficace la veridicità delle postcondizioni.


Efficienza (10): 

(0-3) Posso pensare facilmente ad un algoritmo più efficiente per l'intera consegna

(4-6) Il codice presenta funzioni, o parti di codice che risolvono un sottoproblema, per le quali posso pensare un algoritmo più efficiente

(7-9) Nessun aspetto dell'implementazione può essere reso significativamente più efficiente, sono possibili migliorie di dettaglio (cicli che possono essere eseguiti per un numero minore di iterazioni, variabili superflue)

(10) Il codice non può essere reso più efficiente 


Organizzazione del codice (10): 

(0-2) il codice è realizzato in un unico blocco che realizza molteplici funzionalità e nessuna parte potrà essere riutilizzata

(3-6) la suddivisione in sottoproblemi è chiaramente migliorabile (ad esempio qualche funzione risolve molteplici problemi). 

(7-9) Ciascuna funzione risolve un problema. Si sarebbero potute sfruttare funzioni disponibili (implementate in precedenza o di libreria che sono conosciute) senza incidere sull’efficienza del programma

(10) La divisione in funzioni organizza il codice in modo chiaro e permette la massima riusabilità delle stesse


Stile (10):

(0-2) il codice è difficile da leggere anche da chi conosce il problema e come risolverlo. Ad esempio non è indicato cosa calcola il codice, il codice realizza in un unico blocco molteplici funzionalità, i commenti sono assenti

(3-6) Viene indicato cosa calcola il codice e le funzioni in esso (tramite commenti e pre post condizioni) ma è difficile capire come vengono realizzate le funzioni per mancanza di commenti informativi, specialmente in frammenti di codice difficili da comprendere, o perché alcune scelte implementative sono controintuitive (soluzioni molto più contorte del necessario). 

(7-9) Si capisce cosa e come viene calcolato. Sono possibili migliorie per velocizzare la comprensione del codice, come ad esempio l’uso di nomi significativi per gli identificatori ed una riorganizzazione del codice che non incida sull’efficienza

(10) Il codice non può essere reso più facile da comprendere senza modificare l'algoritmo implementato.

Consegnare un file .c con il codice che realizza la consegna seguente.

-----

* Implementare un'applicazione per cifrare/decifrare messaggi. 

*  - Cifratura -

* La cifratura avviene modificando solamente i caratteri

 * alfanumerici (ovvero le cifre 0-9, le lettere minuscole

 * a-z, le lettere maiuscole A-Z) del messaggio nel 

 * modo seguente: dato il valore numerico

 * corrispondente ad un carattere (es. a=97, A=65, valori ottenibili stampando i caratteri come interi printf("%d",'a'); ), e dato un 

 * intero k!=0, la cifratura di un carattere avviene sommando k 

 * al valore numerico del carattere.  

 * Ad esempio se k=2 'a' viene trasformata in 'c', 'B' in 'D', '1' 

 * in '3', '!' in '!' (perché non è un carattere alfanumerico). 

 * Inoltre si deve assicurare che ogni cifra 

 * sia trasformata in una cifra, ogni lettera minuscola in

 * una lettera minuscola, ogni lettera maiuscola in una

 * lettera maiuscola. Ciò si ottiene considerando 'a' il 

 * carattere seguente di 'z', 'A' quello di 'Z', '0' quello di '9'. 

 * Ad esempio se k=3 'y' viene trasformata in 'b', 'Z' in 'C', 

 * '7' in '0'.

 * 

 * 

 * - Decifratura - 

 * 

 * Per decifrare un messaggio è sufficiente ri-cifrare il

 * messaggio con la chiave di segno opposto. Quindi se si è

 * cifrato un messaggio con k=2, basta ricifrarlo con k=-2

 * per decifrarlo. 

 * 

 * 

 * - Chiave di Cifratura -

 * 

 * Una chiave di cifratura k è valida se diversa da 0.

 * Prima di poter cifrare/decifrare un messaggio, è 

 * necessario assicurarsi che l'utente abbia inserito una

 * chiave e che tale chiave sia valida. Si deve stampare un 

 * messaggio di errore in caso contrario.

 * 

 * 

 * - Interfaccia -

 * 

 * L'applicazione fornisce un messaggio di saluto all'inizio

 * dell'esecuzione:

   ---------------------

   Benvenuto in CrittApp

   ---------------------

 * seguito dal seguente menu: 

   Scegliere una delle seguenti opzioni:

   

   1) specificare la chiave di cifratura

   2) codifica un messaggio

   3) decodifica un messaggio

   4) esci

 

   Indicare il carattere corrispondente e premere Invio:

 * 

 * L'utente può inserire uno dei caratteri 1,2,3,4 e premere Invio. 

 * 1 chiederà una nuova chiave all'utente. Solo chiavi

 * diverse da 0 sono valide; l'applicazione continua a 

 * chiedere una nuova chiave fino a quando quella 

 * inserita è valida.  

 * 2 chiederà il messaggio da cifrare e stamperà il

 * messaggio cifrato.

 * 3 chiederà il messaggio da decifrare e stamperà il

 * messaggio decifrato.

 * 4 esce dall'applicazione. 

 * Una volta eseguita una delle operazioni sopra, il menu

 * viene stampato di nuovo (a meno che il comando 

 * selezionato sia stato 4). Se l'utente non seleziona 

 * un carattere valido tra 1,2,3,4, gestire l'errore. 

 * 

 * L'unica libreria che può essere inclusa nel vostro 

 * codice è stdio.h.

* Nel caso che vogliate leggere da input una stringa ed assegnarla ad un array di caratteri, potete evitare di controllare che l’input sia 

* più piccolo della dimensione dell’array ed assumere, commentando opportunamente, che l’utente si "comporti bene". Allo stesso modo 

* quando si chiede un intero, potete assumere che l'utente effettivamente digiti un intero (anche se non necessariamente l'intero che

* ci aspettiamo)
 */