function displayAbbreviations(){
	if(!document.getElementsByTagName)
		return false;
	if(!document.createElement)
		return false;
	if(!document.createTextNode)
		return false;
	//获取所有缩略词
	var abbrs=document.getElementsByTagName("abbr");
	if(abbrs.length<1)
		return false;
	
	var defs=new Array();
	//遍历这些缩略词
	for(var i=0;i<abbrs.length;i++)
	{
		var key=abbrs[i].firstChild.nodeValue;
		var definition=abbrs[i].getAttribute("title");
		defs[key]=definition;
	}
	//创建标题
	var h2=document.createElement("h2");
	var h2_text=document.createTextNode("Abbreviations");
	h2.appendChild(h2_text);
	document.body.appendChild(h2);
	//创建定义列表
	var dlist=document.createElement("dl");
	
	for(key in defs)
	{
		//创建定义标题
		var dtitle=document.createElement("dt");
		var dtitle_text=document.createTextNode(key);
		dtitle.appendChild(dtitle_text);
		//创建定义内容
		var ddesc=document.createElement("dd");
		var ddesc_text=document.createTextNode(defs[key]);
		ddesc.appendChild(ddesc_text);
		
		dlist.appendChild(dtitle);
		dlist.appendChild(ddesc);
	}
	
	document.body.appendChild(dlist);
}
addLoadEvent(displayAbbreviations);