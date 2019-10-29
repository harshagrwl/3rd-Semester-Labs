disp('Arithmatic Decoding: ');
rec='a';
tagr=tag;
for i=1:le
    for j=1:larith(2)
        if(tagr<ar(j) && tagr>(ar(j)-p(j)))
            rec(i)=new(j);
            nm=j;
        end
    end
    if(nm>1)
    tagr=(tagr-ar(nm-1))/p(nm);
    else
    tagr=tagr/p(nm);
    end
end
disp(['Recieved word is       ',rec]);
if(rec==arith)
    disp('Word is correct');
else
    disp('Word is not correct');
end