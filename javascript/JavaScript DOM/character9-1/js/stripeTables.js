function stripeTables(){
	if(!document.getElementsByTagName)
		return false;
	var tables=document.getElementsByTagName("table");
	for(var i=0;i<tables.length;i++){
		var trs=tables[i].getElementsByTagName("tr");
		if(trs.length<1)
			continute;
		var odd=false;
		for(var j=0;j<trs.length;j++){
			if(odd===false){
				odd=true;
			}
			else if(odd===true){
				var tr=trs[j];
//				tr.style.backgroundColor="#ffc";
				addClassName(tr,"intro");
				odd=false;
			}
		}
	}
}
addLoadEvent(stripeTables);