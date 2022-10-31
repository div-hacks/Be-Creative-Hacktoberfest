class Permutation {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        permuteHelper(list, new ArrayList<>(), nums);
        return list;
    }
    private void permuteHelper(List<List<Integer>> list, List<Integer> resultList, int [] arr)
    {
 
        if(resultList.size() == arr.length)
        {
            list.add(new ArrayList<>(resultList));
        } 
        else
        {
            for(int i = 0; i < arr.length; i++)
            { 
 
                if(resultList.contains(arr[i])) 
                {
                    // If element already exists in the list then skip
                    continue; 
                }
                // Choose element
                resultList.add(arr[i]);
                permuteHelper(list, resultList, arr);
                resultList.remove(resultList.size() - 1);
            }
        }
    }
}
