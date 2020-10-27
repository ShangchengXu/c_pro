fid = fopen('weight_c0.txt','w');
weight = normrnd(0,1,6,25);
for i = 1:1:6
    for j = 1:1:25
        fprintf(fid,'%f\t',weight(i,j));
    end
    fprintf(fid,'\n');
end
fid2 = fopen('weight_c2.txt','w');  
weight = normrnd(0.1,0.9,6,25);
for i = 1:1:6
    for j = 1:1:25
        fprintf(fid2,'%f\t',weight(i,j));
    end
    fprintf(fid2,'\n');
end
fid3 = fopen('weight_c4.txt','w');
weight = normrnd(0.1,0.9,10,16);
for i = 1:1:10
    for j = 1:1:16
        fprintf(fid3,'%f\t',weight(i,j));
    end
    fprintf(fid3,'\n');
end
fclose(fid);
fclose(fid2);
fclose(fid3);