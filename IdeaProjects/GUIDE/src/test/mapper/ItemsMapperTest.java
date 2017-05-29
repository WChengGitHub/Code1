package mapper;

import com.sun.mail.imap.protocol.Item;
import org.junit.Before;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import pojo.Items;
import pojo.ItemsExample;

import java.util.List;

import static org.junit.Assert.*;

/**
 * Created by user on 2017/3/12.
 */
public class ItemsMapperTest {
    private ApplicationContext applicationContext;
    private ItemsMapper itemsMapper;
    @Before
    public void setUp() throws Exception {
        applicationContext=new ClassPathXmlApplicationContext("spring/applicationContext-Dao.xml");
        itemsMapper= (ItemsMapper) applicationContext.getBean("itemsMapper");
    }

    @Test
    public void testDeleteByPrimaryKey() throws Exception {

    }

    @Test
    public void testInsert() throws Exception {

    }

    @Test
    public void testSelectByExample() throws Exception {
        ItemsExample itemsExample=new ItemsExample();
        ItemsExample.Criteria criteria=itemsExample.createCriteria();
        criteria.andNameEqualTo("笔记本");
        List<Items> itemsList=itemsMapper.selectByExample(itemsExample);
        System.out.println(itemsList);
    }

    @Test
    public void testSelectByPrimaryKey() throws Exception {
       Items items=itemsMapper.selectByPrimaryKey(1);
        System.out.println(items);
    }

    @Test
    public void testUpdateByPrimaryKey() throws Exception {

    }
}