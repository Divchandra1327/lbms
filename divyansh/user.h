char genrateusername(char email[50],char username[50]){
	int i;
	for(i=0;i<strlen(email);i++){
		if(email[i]=='@'){
		    break;
		} 
		else {
		   username[i]=email[i];
		}
	}
}
