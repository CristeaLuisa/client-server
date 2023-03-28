
//1. Comunicare prin socket stream, IPv4 cu serverul Web ales. Programul client Linux se va realiza astfel încât să se
//conecteze la server pe portul 80;
//2. Programul client va rula în buclă, afișând meniul de mai jos și așteptând o opțiune introdusă de utilizator:
//1. Conectare la server
//2. Deconectare de la server
//3. Rulare comanda "GET / HTTP/1.0\r\n\r\n"
//4. Iesire din aplicatie
//Introduceti optiunea dorita:_

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define PORT 80
#include <stdlib.h>
#include <string.h>
#define dimensiune 1000
//declarare functi
void Afiseaza_Meniu();
int Citeste_optiune();
void Preluare_optiune(int choice);
int x1;
	int socket1;
	struct sockaddr_in server;
	//crearea socket ului
	char *mesaj,	server_primit[200];
	int rezultat;

int main(int arg ,char argv[]){
  
 
 
  
                                     

        //apelare meniu
	do
	{
        Afiseaza_Meniu();
        x1=Citeste_optiune();
	Preluare_optiune(x1);
	}

        while (x1!='4');
	return 0;

}


void Preluare_optiune(int choice){

  char data[dimensiune];//declarare variabila pentru continutul fisierului

 // FILE *fPtr;//pointerul
  //fPtr=fopen("C:\\index.html","w")
 // if(fPtr==NULL){printf ("Nu s-a creat fisierul");
	  
//	  fgets(server_primit,dimensiune,stdin);}
switch(choice)
{
	case'1':
		{	printf("Conectare la server...\n");


	;

	socket1=socket(AF_INET, SOCK_STREAM ,0);
if(socket1==-1)
	{printf("Nu putem crea socketu\n" );
exit(0);
	}
	else{
		printf("Socket creat!\n");
	
	}

	
	server.sin_family= AF_INET;
	
        server.sin_addr.s_addr= inet_addr("64.90.34.130");

	server.sin_port=htons(80);//transforma un int scurt din ordinea octetilor gazda in ordinea octetilor de retea
	//conectarea socket ului
	 
	if(connect(socket1,(struct sockaddr *)&server,sizeof(server))<0){

printf("Eroare de conectare\n ");
/*return  1;*/

	}
	
	printf("Este conectat cu succes!\n");
		}
	break;


	case '2':
	{
	printf("Deconectare\n");
	
	exit(0);
	}
break;

	case '3':
{
printf("Trimitere comanda");
// functia send
	mesaj= "GET / HTTP/1.0\r\n\r\n";

        if(send (socket1,mesaj, strlen(mesaj),0)<0){

printf("Eroare de trimitere");
//return 1;
	}
	printf("Datele sunt transmise \n");

//bucla

// functia recive

do{  
rezultat=recv(socket1,server_primit,200,0);
//fputs(server_primit,fPtr);

if(rezultat>0)
	
        printf(server_primit); 




else if(rezultat==0)
	printf("Conectare finalizata");
   

else 

printf("Conectare esuata!!!");
 
//fputs(server_primit,fPtr);
//fclose(fPtr);


}while (rezultat>0);

	} 
break;

case '4':
{
printf("Iesire\n");
}
break;


}
}
void Afiseaza_Meniu(){

printf("1.Conectare la server\n");
printf("2.Deconectare de la server\n");
printf("3.Trimite comanda\n");
printf("4.Iesire\n");

}
 
int Citeste_optiune(){
int v,v1,i;
i=0;
do
{
v=getchar();
if(i==0)
	v1=v;
++i;

}
while(v!='\n');
return v1;
}





