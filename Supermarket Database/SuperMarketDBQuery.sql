USE SuperMarketDB;
GO 
/* First query*/
select PName  from PRODUCT
where quantity_bought in 
 (select MAX(quantity_bought) from product )

 /* second query*/
select PName as "product name " from PRODUCT 
where quantity_bought =0  and Pmonth = 'may' 

/* third query */ 
select FirstName from person  
where person.id  in 
(select customerid from PURCHASE  where Pyear  <> 2022 and Pyear = 2021)

/* fourth query */
select FirstName from person  
where person.id  in
(SELECT customerid from PURCHASE WHERE TotalPrice in  
(select max (Totalprice) from  PURCHASE) ) 

/* fifth query */ 
select  PType from PRODUCT 
where PId in 
(select ProductId from PURCHASE where TotalAmount in 
(select MAX(TotalAmount )from PURCHASE) )

/* sixth query */ 
SELECT *
FROM PRODUCT

