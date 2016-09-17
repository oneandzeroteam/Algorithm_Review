class TestCase
  def initialize(number_of_students, number_of_pairs, relationships)
    @number_of_students = number_of_students.to_i
    @number_of_pairs = number_of_pairs.to_i
    @relationships = relationships
    @index_of_relations = Hash.new
    (0..@number_of_students - 1).each do |index|
      @index_of_relations[index] = Array.new
    end
  end

  def define_relations
    (0..@number_of_pairs - 1).each do
      pair = @relationships.shift(2)
      @index_of_relations[pair.min.to_i] << pair.max.to_i
    end
  end

  def compute_possibilities
    @paths = []
    hash = @index_of_relations.dup
    path = Hash.new
    hash.each{ |k,v| path[k] = nil }
    pair_recursion(hash, path, 0)
    puts "#{@paths.count}"
  end


  def pair_recursion(hash, path, index)
    return if hash.empty?

    values = @index_of_relations[index]
    allowed_paths = []

    if not path.key(index).nil?
      path[index] = path.key(index)
      allowed_paths << path
    else
      values.each do |value|
        next if not path.key(value).nil?
        path[index] = value
        allowed_paths << path.dup
      end
    end

    @paths << path if valid_path path

    hash.shift
    allowed_paths.map { |p| pair_recursion hash.dup, p , index+1 }
  end

  def valid_path(hash)
    valid_flag = true
    hash.each_value do |value|
      valid_flag = false if value == nil
    end
    return valid_flag
  end
end

input = $stdin.readlines
number_of_test_cases = input.shift.to_i
output = []

(1..number_of_test_cases).each do |index|
  test_case_input = input.shift(2)
  test_case_properties = test_case_input[0].split(' ')
  test_case_relations = test_case_input[1].split(' ')

  t = TestCase.new(test_case_properties[0],
                   test_case_properties[1],
                   test_case_relations)

  t.define_relations
  t.compute_possibilities
end
