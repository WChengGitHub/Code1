function displayCiations(){
	if(!document.getElementsByTagName)
		return false;
	if(!document.createElement)
		return false;
	if(!document.createTextNode)
		return false;
	//获取所有的blockquote元素节点
	var quotes=document.getElementsByTagName("blockquote");
	//遍历所有的blockquote元素节点
	for(var i=0;i<quotes.length;i++){
		if(!quotes[i].getAttribute("cite"))
			continue;
	
		var source=quotes[i].getAttribute("cite");
		
		var a=document.createElement("a");
		var a_text=document.createTextNode(source);
		a.setAttribute("href",source);
		a.appendChild(a_text);
		
		var quoteChilds=quotes[i].getElementsByTagName("*");
		quoteChilds[quoteChilds.length-1].appendChild(a);
	}
}
addLoadEvent(displayCiations);