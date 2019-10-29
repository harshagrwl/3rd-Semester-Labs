p=[0.4 0.2 0.2 0.1 0.1];
n=length(p);
codeword=cell(1,n);
X=zeros(n,n);
temp=p;
for i=1:n-1
[~ ,l]=sort(temp);
disp(l)
X(l(1),i)=10;
X(l(2),i)=11;
temp(l(2))=temp(l(2))+temp(l(1));
temp(l(1))=100;
disp(temp)
end
X
i=n-1;
rows=find(X(:,i)==10);
codeword(rows)=strcat(codeword(rows),'1');
rows=find(X(:,i)==11);
codeword(rows)=strcat(codeword(rows),'0');
codeword
for i=n-2:-1:1
row11=find(X(:,i)==11);
    row10=find(X(:,i)==10);
    codeword(row10)=strcat(codeword(row11),'1');
    codeword(row11)=strcat(codeword(row11),'0');
end
disp(codeword)