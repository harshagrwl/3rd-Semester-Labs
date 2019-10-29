clc;
clear all;
close all;
sig=1:5;
Symbols=[1 2 3 4 5];
P=[0.12 0.04 0.45 0.16 0.23];
dict = huffmandict(Symbols,P);
temp=dict;
for i=1: length(temp)
    temp {i,2}= num2str(temp{i,2});
end
disp(temp);
hcode= huffmanenco(sig,dict)
dhsig= huffmandeco(hcode, dict)