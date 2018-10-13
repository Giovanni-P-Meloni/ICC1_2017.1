 FILE *ImgPtr;
    char headertype[50];
    char comentario[50]; // comentario da imagem que devo pular
    Imagem parte; // A imagem eh composta por diferentes partes, "parte" sera um ponteiro que aponta para uma delas.

    // Primeira entrada e` a Operacao desejada pelo usuario
    scanf("%d", &Operacao);// Existem 3 possibilidades: Operacao == 1 -> FuncLog || Operacao == 2 -> FuncStretching || Operacao == 3 -> FuncBucket

    // Proxima entrada e` o nome do arquivo, portanto alocarei ele numa string.
    NomeDoArq(&filename);
    LoadImage(filename, &parte);

            // Abrindo o arquivo de imagem
    ImgPtr = fopen(filename, "r");
    // Primeira parte do cabecalho me diz COMO a imagem esta armazenada, portanto, em headertype,
    // terei "P<n>".
    fgets(headertype, 50, ImgPtr); //Primeira linha sera composta por 'P', '<n>' e >>'\n'<<
    tam1 = strlen(headertype);
    headertype[tam1-1] = '\0';
    if(!strcmp(headertype, "P2")) parte.isAsc = true;
    else parte.isAsc = false;

    // Segunda parte do cabecalho consiste do comentario, que pode ser ignorado
    fgets(comentario, 50, ImgPtr);
    tam1 = strlen(comentario);
    comentario[tam1-1] = '\0';

    //Terceira parte do cabecalho me diz quais as DIMENSOES da matriz imagem
    fscanf(ImgPtr, "%d", &parte.XDIM);
    fscanf(ImgPtr, "%d", &parte.YDIM);

    //Quarta parte do cabecalho me diz qual o o valor do MAIOR pixel encontrado na imagem.
    fscanf(ImgPtr, "%d", &parte.max)

    //Quinta parte me passa a matriz de fato



    printf("XDIM: %d, YDIM: %d, /n Max: %d e ASCII?: %d", parte.XDIM, parte.YDIM, parte.max, parte.isAsc);
