%function AdjacencyMatrix = ReadInputFromTriang(input)
close all;
clc;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The code needs the input file "Input.txt" in which there are the
% neighbor lists of all triangulations got from the modified Sulanke's
% code. We can find some examples in the folder RESULT that I have made.
% Then this code will build the adjacency matrix for each triang and
% another one for the union. 

LATEX_CODE='';
Mathematica_FinalString='';
for ID=1:3
    clearvars -except ID LATEX_CODE Mathematica_FinalString
    
    GENUS=1;
    ORIENT=1;
    
    
    filename = ['Input' num2str(ID) '.txt'];
    fid  = fopen( filename, 'r' ) ;

    Mathematica_EdgesString = '';
    CNT=0;
    while true
        line = fgetl( fid );
        if line == -1
            break;
        end;

        Data = strsplit(line, ':');

        if ~cellfun('isempty', Data)
            if numel(Data) == 1

                CNT = CNT+1;
                Mathematica_EdgesString{CNT}='';
            else
                CURRENT_VERTEX = str2double(Data{1})+1;
                LIST = strsplit(Data{2}, ' ');
                LIST = str2double(LIST(2:end))+ 1;


                for i=1:numel(LIST)
                    if(CURRENT_VERTEX < LIST(i))
                        Mathematica_EdgesString{CNT}=[Mathematica_EdgesString{CNT} num2str(CURRENT_VERTEX) '<->' num2str(LIST(i)) ', '];

                        AdjacencyMatrix(CURRENT_VERTEX,LIST(i),CNT)=1;
                        AdjacencyMatrix(LIST(i),CURRENT_VERTEX,CNT)=1;
                    end;
                end; 
            end;
        end;

    end;
    
    VERTICES=numel(AdjacencyMatrix(:,1,1));
    fclose( fid ) ;
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    for i=1:numel(AdjacencyMatrix(:,1,1))
        for j=1:numel(AdjacencyMatrix(:,1,1))
            if AdjacencyMatrix(i,j,1) == 1 || AdjacencyMatrix(i,j,2) == 1
                AdjacencyMatrixUNION(i,j)=1;
            end;
        end;
    end;

    DSATUR_INPUT(1,1) = numel(AdjacencyMatrixUNION(:,1));
    START=1;
    for i=1:numel(AdjacencyMatrixUNION(:,1))-1
        for j=i+1:numel(AdjacencyMatrixUNION(:,1))
            if AdjacencyMatrixUNION(i,j) ~=0
                START = START + 1;
                DSATUR_INPUT(START,1:2) = [i j];
            end;
        end;
    end;
    DSATUR_INPUT(1,2) = numel(DSATUR_INPUT(:,1));


    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% In this part, MATLAB will generate a file "Color Input.txt" as the input of the coloring program "dsatur.exe".
    %% The outcome from dsatur.exe would be the list of proper colors used for coloring the vertices.
    fid=fopen('ColorInput.txt','w');
    for i=1:numel(DSATUR_INPUT(:,1))
        fprintf(fid, '%d %d\n', [DSATUR_INPUT(i,1) DSATUR_INPUT(i,2)]');
    end;
    fclose(fid);

    [status,cmdout] = dos('dsatur.exe ColorInput.txt');
    
    %%%%%
    B=strsplit(cmdout,',');
    MAX=0;
    for i=1:numel(B)
        if MAX < str2num(B{i})
            MAX = str2num(B{i});
        end;
    end
    
    disp([num2str(ID) '    ' num2str(MAX) '   ' cmdout(2:end)]);
    mvc = str2double(strsplit(cmdout,','));

    for i=2:DSATUR_INPUT(:,1)
        if mvc(DSATUR_INPUT(i,1)) == mvc(DSATUR_INPUT(i,2))
            disp('FAILED');
            return
        end;
    end;

    disp('CORRECT!!!');
    OUTPUT = ['mvc = {' num2str(mvc(1))];

    for i=2:numel(mvc)
        OUTPUT = [OUTPUT ',' num2str(mvc(i))];
    end;

    OUTPUT = [OUTPUT '};'];
    clipboard('copy',OUTPUT);

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Generate Mathematica CODE
    VERTEX_LIST = '';
    for i=1:VERTICES
        VERTEX_LIST = [VERTEX_LIST num2str(i)];
        if i ~= VERTICES
            VERTEX_LIST = [VERTEX_LIST ','];
        end;
    end;
    
    
    Mathematica_Header = ']=System`Graph[{';
    Mathematica_Tail   = ['}, GraphLayout->"PlanarEmbedding", VertexLabels -> "Name", System`VertexStyle -> Thread[{' VERTEX_LIST ...
                           '}-> (ColorData[97] /@ {' cmdout(2:end) ...
                           '})], VertexSize -> 0.4, VertexLabelStyle -> Directive[Black, 20],  EdgeStyle -> {{Thickness[0.004], Black}}]\r\n'];
                       
    for i=1:numel(Mathematica_EdgesString)             
        Mathematica_FinalString = [Mathematica_FinalString 'G[', num2str(2*ID-2+i), Mathematica_Header, Mathematica_EdgesString{i}(1:end-2), Mathematica_Tail];
        Mathematica_FinalString = [Mathematica_FinalString 'Export["t' num2str(ceil(ID-1/2)) '_' num2str(i) '.eps",G[' num2str(ID) ']]\r\n\r\n'];
        %%%
        %% Mathematica_FinalString will be the code that you can use to visualize it in Mathematica. 
    end;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Generate File.csv to generate table in Latex
    fileID = fopen(['FILE' num2str(ID) '.csv'],'w');
    fprintf(fileID,'Triang 1, Triang 2\n');

    for i=1:numel(AdjacencyMatrix(:,1,1))
        for k=1:numel(AdjacencyMatrix(1,1,:))
            fprintf(fileID,'%d:', i);
            for j=1:numel(AdjacencyMatrix(1,:,1))
                if AdjacencyMatrix(i,j,k) == 1
                    fprintf(fileID,' %d', j);
                end;
            end;

            if k ~= numel(AdjacencyMatrix(1,1,:))
                fprintf(fileID,',');
            else
                fprintf(fileID,'\n');
            end;
        end;
    end;

    %% GENERATE LATEX CODE
    LATEX_CODE = [LATEX_CODE '\begin{table}[]\r\n' '\centering\r\n' ...
                  '\caption{nv=' num2str(VERTICES) ', genus=' num2str(GENUS) ', orient=' num2str(ORIENT) ', thickness=2, $K_3$-free, $\chi=' num2str(MAX) '$}\r\n\r\n' ...
                  'Color List: '  cmdout(2:end) '\r\n' ...
                  '\nth{' num2str(ID) '} Embedding \r\n\r\n' ...
                  '\begin{tabular}{|l|l|}\r\n\hline\r\n' ...
                  'Triang 1 & Triang 2 \\ \hline\r\n' ...
                 ];
    
    for i=1:VERTICES
        for k=1:2
            LATEX_CODE = [LATEX_CODE num2str(i) ':'];
            
            for j=1:VERTICES
                if AdjacencyMatrix(i,j,k)==1
                    LATEX_CODE = [LATEX_CODE ' ' num2str(j)];
                end;
            end;
            
            if k==1
                LATEX_CODE = [LATEX_CODE ' & '];
            else
                LATEX_CODE = [LATEX_CODE ' \\ \hline\r\n'];
            end;  
        end;
    end;
    
    LATEX_CODE = [LATEX_CODE '\end{tabular}\r\n\end{table}\r\n\r\n' ...
%                    '\clearpage\r\n\r\n' ...
%                    '\begin{center}\r\n  \begin{figure}\r\n  	\includegraphics[scale=0.6]{Images/t' num2str(ceil(ID-1/2)) '_1.eps}\r\n\r\n' ...
%                    '    \caption{Triang 1' ...
%                    ' - nv=' num2str(VERTICES) ', genus=' num2str(GENUS) ', orient=' num2str(ORIENT) ', thickness=2, $K_3$-free, $\chi=' num2str(MAX) '$}\r\n' ...
%                    '    Color List: '  cmdout(2:end) '\r\n  \end{figure}\r\n\r\n  \begin{figure}\r\n' ...                   
%                    '  	\includegraphics[scale=0.6]{Images/t' num2str(ceil(ID-1/2)) '_2.eps}\r\n\r\n' ...
%                    '    \caption{Triang 2' ...
%                    ' - nv=' num2str(VERTICES) ', genus=' num2str(GENUS) ', orient=' num2str(ORIENT) ', thickness=2, $K_3$-free, $\chi=' num2str(MAX) '$}\r\n' ...
%                    '    Color List: '  cmdout(2:end) '\r\n  \end{figure}\r\n' ...
%                    '\end{center}\r\n\r\n\r\n' ... 
                  ];
              
    
    fclose(fileID);
end;