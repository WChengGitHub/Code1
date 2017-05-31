function styleHeaderSiblings(){
	if(!document.getElementsByTagName)
		return false;
	var headers=document.getElementsByTagName("h1");
	for(var i=0;i<headers.length;i++){
		var nextNode=getNextElement(headers[i]);
		if(!nextNode){
			continue;
		}
		nextNode.style.fontWeight="bold";
		nextNode.style.fontsize="1.2em";
	}
}
addLoadEvent(styleHeaderSiblings);