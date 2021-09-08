clc;
close all;
clear all;
pkg load communications;

%sym = ['x1' 'x2' 'x3' 'x4' 'x5']
%prob = [0.4,0.19,0.16,0.15,0.1]
sym = input('Enter symbols:');
prob = input('Enter probabilities:');

[dict] = huffmandict(sym,prob)

%sig = randsrc(100,1,[sym;prob])
%code = huffmanenco(sig,dict)
%decosig = huffmandeco(code,dict)
%printf(isequal(sig,decosig))

H=0;
for k=1:length(prob)
  H=H+prob(k)*log2(1/prob(k));
end
disp("Entropy of DMS")
printf("H= %f bits/symbol\n",H);

L=0;
for k=1:length(prob)
  L=L+prob(k)*length(dict{k});
end
disp("Average Coodeword Length")
printf("L= %f bits/symbol\n",L);

E=0;
E=H/L;
disp("Code Efficiency")
printf("E= %f percent\n",E*100);

R=0;
R=1-E;
disp("Code Redundancy")
printf("R= %f percent\n",R*100);