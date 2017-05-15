close all;

clear all;
clc;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
EdgeList = '{1<->3,1<->8,1<->10,1<->12,2<->4,2<->6,2<->9,2<->12,2<->17,2<->19,3<->7,3<->8,3<->10,3<->12,3<->13,3<->16,4<->9,4<->11,4<->17,5<->8,5<->10,5<->18,6<->17,6<->19,7<->10,7<->13,8<->10,8<->13,8<->18,9<->11,9<->19,10<->12,10<->13,10<->16,10<->18,11<->17,11<->19,12<->16,12<->19,13<->18,17<->19}';
EdgeList = strrep(EdgeList,'{','[');
EdgeList = strrep(EdgeList,'}',']');
EdgeList = strrep(EdgeList,'<->',' ');
EdgeList = strrep(EdgeList,',',';');

NeighborList = str2num(EdgeList);

START=0;
COUNTER1=0;
for i=1:numel(NeighborList(:,1))
    if START~=NeighborList(i,1)
        START=NeighborList(i,1);
        COUNTER1 = COUNTER1 + 1;
        COUNTER2 = 1;
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        N(COUNTER1,COUNTER2) = NeighborList(i,1);     
    end;
    
    COUNTER2 = COUNTER2 + 1;
    N(COUNTER1,COUNTER2) = NeighborList(i,2);    
end;
%%%%%%%%%%%%%
OUTPUT='';
for i=1:numel(N(:,1))
    if isempty(find(N(i,:) == 0))
        END = numel(N(i,:));
    else
        N2 = find(N(i,:)==0);
        END= N2(1)-1;
    end;
    
    
    
    OUTPUT = [OUTPUT '-' num2str(N(i,1))];
    for j=2:END
        OUTPUT = [OUTPUT ' ' num2str(N(i,j)) ];
    end;
    
    if i==numel(N(:,1))
        OUTPUT = [OUTPUT ' 0'];
    end;
    OUTPUT = [OUTPUT '\n'];
end

OUTPUT = [OUTPUT '&Coordinates of vertices:\n'];
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
VertexCoordinates='{0., 0.}, {9., 2.}, {6., 2.}, {10., 5.}, {2., 5.}, {10., 2.}, {5., 3.}, {1., 3.}, {9., 7.}, {0., 10.}, {12., 3.}, {9., 1.}, {4., 3.}, $Failed, $Failed, {7., 2.}, {10., 3.}, {3., 4.}, {16., 0.}';

VertexCoordinates=strrep(VertexCoordinates,' $Failed,',' 5 5;');
VertexCoordinates=strrep(VertexCoordinates,'{','[');
VertexCoordinates=strrep(VertexCoordinates,'}',']');
VertexCoordinates=strrep(VertexCoordinates,'.,',' ');
VertexCoordinates=strrep(VertexCoordinates,'.],',';');
VertexCoordinates=strrep(VertexCoordinates,'; [','; ');
VertexCoordinates=strrep(VertexCoordinates,'.]',']');

A = str2num(VertexCoordinates);

%OUTPUT='';
for i=1:numel(A(:,1))
    for j=1:numel(A(1,:))
        if j==1
            B(i,j) = 200 + A(i,j)*50;
        else
            B(i,j) = 480 - A(i,j)*50;
        end;
    end;
    
    OUTPUT = [OUTPUT '-' num2str(i) ' ' num2str(B(i,1)) ' ' num2str(B(i,2)) '\n'];
end;

sprintf(OUTPUT)