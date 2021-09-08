clc;
close all;
clear all;

p=0.001:0.001:2;
for i=1:1:length(p)
   h(i)=-( p(i) * log2(p(i)) + (1-p(i)) * log2(1-p(i)) );
endfor
plot(p,h)
xlim([0 1])
ylim([0 1])
title('Entropy vs Probability Curve for Binary Source')
grid on

n = input('Enter number of symbols:');
%sym = ['x1' 'x2' 'x3' 'x4' 'x5']
%prob = [0.4,0.19,0.16,0.15,0.1]
sym = input('Enter symbols:');
prob = input('Enter probabilities:');

H=0;
for k=1:length(prob)
  H=H+prob(k)*log2(1/prob(k));
end

disp("Entropy of DMS")
printf("H= %f bits/symbol\n",H);


