

digitDatasetPath = fullfile(matlabroot,'toolbox','nnet','nndemos', ...
    'nndatasets','DigitDataset');
imds = imageDatastore(digitDatasetPath, ...
    'IncludeSubfolders',true,'LabelSource','foldernames');
% figure;
% perm = randperm(10000,20);
% for i = 1:20
%     subplot(4,5,i);
%     imshow(imds.Files{perm(i)});
% end
labelCount = countEachLabel(imds);
img = readimage(imds,1);
size(img);
numTrainFiles = 750;
[imdsTrain,imdsValidation] = splitEachLabel(imds,numTrainFiles,'randomize');
 layers = [
     imageInputLayer([28 28 1])
     
     convolution2dLayer(3,8,'Padding','same')
     batchNormalizationLayer
     reluLayer
     
     maxPooling2dLayer(2,'Stride',2)
     
     convolution2dLayer(3,16,'Padding','same')
     batchNormalizationLayer
     reluLayer
     
     maxPooling2dLayer(2,'Stride',2)
     
     convolution2dLayer(3,32,'Padding','same')
     batchNormalizationLayer
     reluLayer
     
     fullyConnectedLayer(10)
     softmaxLayer
     classificationLayer];
%  layers = [
%      imageInputLayer([28 28 1],"Name","imageinput")
%     convolution2dLayer([5 5],6,"Name","conv_1")
%     maxPooling2dLayer([2 2],"Name","maxpool","Padding","")
%    convolution2dLayer([5 5],16,"Name","conv_2","Padding","same")
% %    batchNormalizationLayer
%    reluLayer
%     averagePooling2dLayer([2 2],"Name","avgpool2d","Padding","same")
%     fullyConnectedLayer(120,"Name","fc_1")
%    fullyConnectedLayer(10,"Name","fc_2")
%     softmaxLayer("Name","softmax")
%    classificationLayer("Name","classoutput")];
options = trainingOptions('sgdm', ...
    'InitialLearnRate',0.1, ...
    'MaxEpochs',4, ...
    'Shuffle','every-epoch', ...
    'ValidationData',imdsValidation, ...
    'ValidationFrequency',30, ...
    'Verbose',false, ...
    'Plots','training-progress');
net = trainNetwork(imdsTrain,layers,options);