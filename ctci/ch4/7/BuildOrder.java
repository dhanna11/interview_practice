import java.util.*;

public class BuildOrder {

    BuildOrder(String[] projects, String[][] dependencies) {
	depGraph = new DependencyGraph();
	for (String project : projects) {
	    depGraph.addProject(project);
	}
	for (String[] deps : dependencies) {
	    String dependent = deps[0];
	    String project = deps[1];
	    depGraph.addEdge(project, dependent);
	}
    }
    
    public List<Project> getBuildOrder() {
	return getBuildOrder(depGraph.getProjects());
    }
    
    public List<Project> getBuildOrder(List<Project> projects) {
	Set<Project> visted = new HashSet<Project>();
	Set<Project> built = new HashSet<Project>();
	List<Project> buildOrder = new ArrayList<Project>();
	for (Project project : projects) {
	    if (!canBuild(project, built, visted, buildOrder)) {
		return Collections.emptyList();
	    }
	}
	return buildOrder;
    }

    public boolean canBuild(Project project,Set<Project> built , Set<Project> visited, List<Project> buildOrder) {
	if (built.contains(project))
	    return true;
	// cycle detection
	else if (visited.contains(project))
	    return false;
	visited.add(project);
	for (Project dep :  project.getDeps()) {
	    if (!built.contains(dep) && !canBuild(dep, built, visited, buildOrder))
		return false;
	}
	buildOrder.add(project);
	built.add(project);
	return true;
    }

    class Project {
	
	Project (String name) {
	    this.name = name;
	    this.children = new ArrayList<Project>();
	}

	void addChild(Project child) {
	    children.add(child);
	}

	List<Project> getDeps() {
	    return children;
	}

	String name() {
	    return name;
	}
	    
	String name;
	List<Project> children;
    }
    
    class DependencyGraph {

	DependencyGraph() {
	    nodeList = new ArrayList<Project>();
	    nodeMap = new HashMap<String, Project>();
	}
	
	void addProject(String project) {
	    Project node = new Project(project);
	    nodeList.add(node);
	    nodeMap.put(project, node);
	}

	void addEdge(String project, String dep) {
	    Project pnode = nodeMap.get(project);
	    Project pdep = nodeMap.get(dep);
	    pnode.addChild(pdep);
	}

	List<Project> getProjects() {
	    return nodeList;
	}
	List<Project> nodeList;
	Map<String, Project> nodeMap;
    }

    DependencyGraph depGraph;
    public static void main(String[] args) {
	String[] projects = new String[]{"a", "b", "c", "d", "e", "f"};
	String[][] dependencies = new String[][]{{"a","d"}, {"f", "b"}, {"b", "d"}, {"f","a"}, {"d","c"}, {"a", "f"}};
	BuildOrder buildOrder = new BuildOrder(projects, dependencies);
	for (Project project : buildOrder.getBuildOrder())
	    System.out.println(project.name());
    }

}
