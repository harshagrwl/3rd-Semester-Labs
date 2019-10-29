symb = ['A' 'B' 'C' 'D' 'E']
code = codeword
bitstream = ['0' '0' '1' '1' '1' '0' '0' '1' '1' '0' '1' '0']
n=length(symb);
lengths=[];
for i=1:n
    len=length(char(code(i)));
    lengths=[lengths len];
end
disp(lengths)
maxlen=max(lengths);
disp(maxlen)
msg='';
%bitstream length is denoted by streamlen
streamlen=length(bitstream);
disp(streamlen)
i=1;
while i<=streamlen
    j=0;
    while j<maxlen
        c=bitstream(i:i+j);
        ind=1;
        while (ind<=n && ~isequal(char(code(ind)),c))
            ind=ind+1;
        end
        if ind<=n
            msg=[msg char(symb(ind))];
            break
        else j=j+1;
        end
    end
    i=i+j+1;
end
disp(msg)