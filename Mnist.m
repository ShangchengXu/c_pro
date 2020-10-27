fid0 = fopen('train_image.txt','w');
fid1 = fopen('train_lable.txt','w');
for i = 1:1:6000
    a = Train(i,1);
    b = a{1,1};
    a1 = Train(i,2);
    b2 = a1{1,1};
    f2 = b2(1,1);
    for m = 0:1:9
        if( m == f2)
            fprintf(fid1,"%d\t",1);
        else
            fprintf(fid1,"%d\t",0);
        end
    end
    for j = 1:1:28
        for k = 1:1:28
            f = b(j,k)/256;
            fprintf(fid0,"%f\t",f);
        end
    end
    fprintf(fid0,"\n");
    fprintf(fid1,"\n");
end
fclose(fid0);
fclose(fid1);

            
            
    