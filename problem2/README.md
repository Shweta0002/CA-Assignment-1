# CPI Stack Using Performance Monitoring Counters and linear regression

This project uses perf for evaluating capturing event counts such as branch misses, cache misses , I-TLB misses etc. The counts are then converted to CSV file to train linear regression model.



## Download dependencies

Dependencies (for running on local system):
```
Python 3.8 and onwards
Jupyter Notebook
Seaborn
Numpy 
Matplotlib
Pandas
Sklearn
Scipy
```




## Compile

To Run python notebooks(.ipynb files) : 
1)	Open  CMD
2)	Run jupyter notebook
3)	Run every cell one by one using shift+enter
4)	Or run all cells in batch mode using ctrl+A and shift+ enter

To Run python notebooks (.ipynb) on Google Colab online:
 
1)	Upload the file on google colab
2)	Upload the CSV file on google colab or on google drive and import from there Using
   	```
	from google.colab import drive
	drive.mount('/content/drive')    	
5)	Run all cells using Ctrl+ F9

