fid = fopen('weight_c0.txt','w');
weight = normrnd(0,1,6,25);
for i = 1:1:6
    for j = 1:1:25
        fprintf(fid,'%f\t',weight(i,j));
    end
    fprintf(fid,'\n');
end

    