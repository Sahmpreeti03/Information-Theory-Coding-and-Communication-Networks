clc;
close all;
clear all;

#n=7
#k=4
#P=[1 1 0;0 1 1;1 1 1;1 0 1]

n = input("Enter the number of codeword bits : ")
k = input("Enter the number of message bits : ")
P = input("Enter the Parity Matrix : ")

I = eye(k); 
disp("Generator Matrix : ");
G = [I P]

L = 0: (2^k)-1; 
disp("Datawords : ");
d = fliplr(de2bi(L))

disp("Codewords : ");
C = rem(d*G,2)

disp("Weight of Codewords : ");
w = sum(C,2)

disp("Minimum Hamming Distance : ");
dmin=min(w(2,:))

disp("Error detection capacity : ");
td=dmin-1

disp("Error correction capacity : ");
tc=(dmin-1)/2

H = [P' eye(n-k)];  
disp("Parity Check Matrix : ");
H
HT=H'

#r = [1 0 0 0 1 1 0]
#r = [0 1 0 1 0 1 1]
r = input("Enter the Received codeword : ")

disp("Syndrome : ");
S=rem(r*H',2)

if(S==0)
disp("No Error in Codeword");

else
for i = 1 : 1 : size(H')
if(H'(i,1:3)==S)
	r(i) = 1-r(i);
	break;
endif
endfor

disp('Error is in bit : ')
disp(i)

disp('Corrected Codeword :')
disp(r)

endif



